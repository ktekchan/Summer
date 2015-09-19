/*------------------------------------------

Author: Khushboo Tekchandani 
MAC Learning algorithm for VMWare challenge

--------------------------------------------*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>

using namespace std;

struct CompareFirst
{
     CompareFirst(string val) : val_(val) {}
       bool operator()(const pair<string, int>& elem) const {
              return val_ == elem.first;
        }
         private:
           string val_;
};


int main() {

   int num, i;
   int pin;
   string src, dest;
   char *src_firstbyte[1];
   char *dest_firstbyte[1];
   vector<string> pout;
   vector<pair<string, int> > mapping;
   vector<pair<string, int> >::iterator src_got;
   vector<pair<string, int> >::iterator dest_got;

   cin >> num;

   for(i=0; i<num; i++){
      
      /* Read from STDIN */
      cin >> pin;
      cin >> dest;
      cin >> src;

      /* Validating the input based on constraints*/
      if (pin < 0 || pin > 255)
         pout.push_back("invalid");

      /* Assuming the src and dest mac addresses are fed correctly */
      char *temp1 = strdup(dest.c_str());
      char *temp2 = strdup(src.c_str());

      /* Get the first byte of src and dest */
      dest_firstbyte[0] = strtok(temp1, ":");
      src_firstbyte[0] = strtok(temp2, ":");

      /* Convert the first bytes to int */
      stringstream ss;
      int destx, srcx;
      ss << hex << dest_firstbyte[0];
      ss >> destx;

      ss.str(string());
      ss.clear();
      ss << hex << src_firstbyte[0];
      ss >> srcx;

      /* Check the conditions for src and dest */

      /* Check if src and dest are the same */
      if (dest == src){
         src_got = find_if(mapping.begin(),mapping.end(), CompareFirst(src));

         if (src_got == mapping.end()){
            mapping.push_back(make_pair(src,pin));
         }

         pout.push_back("drop");
         continue;
      }

     
      /* Check if source is a multicast address */
      if (srcx % 2 == 1){
         pout.push_back("drop");   
         continue;
      }

      /* Add a mapping src->pin anf update if it already exists */
      else{
         src_got = find_if(mapping.begin(),mapping.end(), CompareFirst(src));
         if (src_got == mapping.end()){
            mapping.push_back(make_pair(src,pin));
         }

         else{

            if (src_got->second != pin){
              mapping.erase(src_got);
              mapping.push_back(make_pair(src,pin));
            }
         }
      }

      /* Check if dest is a multicast address */
      if (destx % 2 == 1){
         pout.push_back("flood");
         continue;
      }

      /* Find the mapping for the destination */ 
      else {
         dest_got = find_if(mapping.begin(),mapping.end(), CompareFirst(dest));
         if (dest_got == mapping.end()){
            pout.push_back("flood");
         }

         else if (dest_got->second == pin){
            pout.push_back("drop");
         }

         else {
            ss.str(string());
            ss.clear();
            ss << dest_got->second;
            string converted(ss.str());
            pout.push_back(converted);
         }
         continue;
      }

  }

   /* Output */
   for (i=0; i<num; i++){
      cout << pout[i] << endl;
   }

   return 0;
}

