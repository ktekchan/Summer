#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <string>
using namespace std;

int main(){

   long long n = 101101;
   char *buff[sizeof(long)*6+1];
   ltoa(n, buff, 10);
   cout << buff << endl;
   return 0;
}

