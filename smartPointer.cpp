/*
 * Khushboo Tekchandani
 * Example of a smart pointer wrapper
 */
#include <iostream>

using namespace std;

// Smart Integer pointer
class smartInt{
   private:
      int *ptr;
   public:
      explicit smartInt(int *p = NULL) {ptr = p;}

      ~smartInt(){delete(ptr);}

      int &operator *() {return *ptr;}
      int *operator ->() {return ptr;}
};

// Smart Generic Pointer
template <class T>
class smartPtr{
   private:
      T *ptr;
   public:
      explicit smartPtr(T *p = NULL){ptr = p;}
      ~smartPtr(){delete(ptr);}

      T &operator *() {return *ptr;}
      T *operator->() {return ptr;}
};

int main(){

   smartInt ptr(new int());
   *ptr = 20;
   cout << *ptr << endl;

   smartPtr<int> pt(new int());
   *pt=220;
   cout << *pt << endl;

   return 0;
}
