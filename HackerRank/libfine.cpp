#include <iostream>

using namespace std;

struct date{
   int day;
   int month;
   int year;
};

int findFine(date actual, date expected){
   
   if(actual.year>expected.year)
      return 10000;

   else if(actual.year<expected.year)
      return 0;

   else{

      if(actual.month<expected.month)
         return 0;

      else if(actual.month==expected.month){
         
            if(actual.day<=expected.day)
               return 0;

            else
               return 15*(actual.day-expected.day);
               
      }

      else
         return 500*(actual.month-expected.month);
   }

}

int main(){
   
   date actual;
   date expected;

   cin >> actual.day;
   cin >> actual.month;
   cin >> actual.year;

   cin >> expected.day;
   cin >> expected.month;
   cin >> expected.year;

   cout << findFine(actual,expected) << endl;

   return 0;
}
