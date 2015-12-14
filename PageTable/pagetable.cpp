/*
 * Author: Khushboo Tekchandani
 * Hierarchical Page table translation
 */

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

// access info 
enum access{
   ACCESS_READ = 1,
   ACCESS_WRITE = 2,
   ACCESS_EXECUTE = 3,
};

// fault info
enum fault{
   FAULT_NONE = 0,
   FAULT_NOT_PRESENT = 1,
   FAULT_MALFORMED = 2,
   FAULT_VIOLATION = 3,
};

// Permissions
#define PTE_P (1 << 0)
#define PTE_R (1 << 1)
#define PTE_W (1 << 2)
#define PTE_X (1 << 3)
#define PTE_L (1 << 4)

/*
 * Bitmask for the given high and low for 32 bits
 */
uint32_t bitmask(int high, int low){

   uint32_t mask;
   mask = (((uint32_t) -1) << (31 - (high - low))) >> (31 - high);
   return mask;
}

/*
 * Read an aligned 32 bit value from physical memory
 */
static uint32_t readPhys(uintptr_t physAddr){

   uint32_t *temp = (uint32_t*)physAddr;
   uint32_t val = *(temp);
   return val;
}

/*
 * Set an aligned 32 bit memory to a given value
 */
void writePhys(uintptr_t physAddr, uint32_t val){
   *((volatile uint32_t *) physAddr) = val;
   return;
}

/*
 * Traverse the page tables rooted at pl3e for the linearAddr and access
 * type.
 * Input:
 * pl3e - The contents of the PL3e register.
 * linearAddr - The linear address being accessed.
 * access - ACCESS_READ, ACCESS_WRITE, or ACCESS_EXECUTE.
 * Return:
 * FAULT_NONE on success.
 * Otherwise FAULT_NOT_PRESENT, FAULT_MALFORMED, or FAULT_VIOLATION.
 * Output:
 * On success, populate *physAddr.
 */
static enum fault
linearToPhys(uint32_t pl3e, uint32_t linearAddr, enum access access,
      uint32_t *physAddr /*OUT*/){

   uint32_t permissions;
   uint32_t pte;

   // 4GiB pages
   pte = pl3e;
   permissions = pte & (PTE_R | PTE_W | PTE_X);

   // check if the page is present
   if((pte & PTE_P) != 0)
      return FAULT_NOT_PRESENT;

   if((pte & PTE_L) != 0){

      // For a 4GiB page check if the bits from 31 - 12 are 0
      if(bitmask(31,12) != 0)
         return FAULT_MALFORMED;

      // Check the permissions against access
      if((permissions & (1 << access)) == 0)
         return FAULT_VIOLATION;

      // Valid address and translation
      *physAddr = linearAddr;
      return FAULT_NONE;
   }

   // 4MiB pages
   pte = readPhys((pte & bitmask(31,12)) | (((linearAddr & bitmask(31,22)) >> 22) * 4));

   // check if the page is present
   if((pte & PTE_P) != 0)
      return FAULT_NOT_PRESENT;

   if((pte & PTE_L) != 0){

      // For a 4MiB page, check if the bits from 21 - 12 are 0
      if(bitmask(21,12) != 0)
         return FAULT_MALFORMED;

      // Check the permissions against access
      if((permissions & (1 << access)) == 0)
         return FAULT_VIOLATION;

      // Valid address and translation
      *physAddr = (pte & bitmask(31,22)) | (linearAddr & bitmask(21,0)); 
      return FAULT_NONE;
   }

   // 4KiB pages
   pte = readPhys((pte & bitmask(31,12)) | (((linearAddr & bitmask(21,12)) >> 12) * 4));

   // check if the page is present
   if((pte & PTE_P) != 0)
      return FAULT_NOT_PRESENT;

   // Check if it is not a leaf (4KiB pages are always a leaf)
   if((pte & PTE_L) != 0)
      return FAULT_MALFORMED;

   // Check the permissions against access
   if((permissions & (1 << access)) == 0)
      return FAULT_VIOLATION;

   // Valid address and translation
   *physAddr = (pte & bitmask(31,12)) | (linearAddr & bitmask(11,0));
   return FAULT_NONE;
}

int main(){

   string line;
   uint32_t pl3e;
   while (getline(cin, line)){

      if(line[0] == '#'){
         // ignore this line
         continue;
      }

      char *command;
      char *cstr = new char[line.length() + 1];
      cstr[line.length()] = '\0';
      strcpy(cstr, line.c_str());
      command = strtok(cstr, " ");

      if(strcasecmp(command, "pl3e") == 0){
         command = strtok (NULL, " ");
         memcpy(&pl3e, command, sizeof(command));
      }

      else if(strcasecmp(command, "memory") == 0){
         command = strtok(NULL, " =");
         uint32_t physAddr;
         memcpy(&physAddr, command, sizeof(command));

         command = strtok(NULL, " =");
         uint32_t val;
         memcpy(&val, command, sizeof(command));
         writePhys(physAddr, val);
      }

      else{
         cout << command << " -> ";
         uint32_t linearAddr;
         uint32_t *physAddr;

         command = strtok(NULL, " ");
         access curr_access;
         if(strcasecmp(command, "READ") == 0)
            curr_access = ACCESS_READ;
         else if(strcasecmp(command, "WRITE") == 0)
            curr_access = ACCESS_WRITE;
         else
            curr_access = ACCESS_EXECUTE;

         command = strtok(NULL, " ");
         memcpy(&linearAddr, command, sizeof(command));
         cout << linearToPhys(pl3e,linearAddr, curr_access, physAddr) << endl;
      } 
 
   }
}
