/*
 * Author: Khushboo Tekchandani
 * Merge overlapping intervals. Resultant output should only have mutually
 * exclusive intervals
 */

#include <iostream>
#include <stack>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

struct interval{
   
   int start;
   int end;
};

// Helper function to compare the intervals based on their start value
bool compareIntervals(interval i1, interval i2){

   return (i1.start <  i2.start ? true : false);

}

// Function to merge the intervals
void mergeIntervals (vector<interval> &intervals){

   if(intervals.size()<=0)
      return;

   //stack to store intervals
   stack<interval> s;

   //sort the intervals based on the start. Use the helper function
   sort(intervals.begin(),intervals.end(),compareIntervals);

   s.push(intervals[0]);

   int i;

   for(i=1; i<intervals.size(); i++){
   
      interval temp = s.top();

      //compare the ith intervals starting with the end of top
      if (temp.end < intervals[i].start){
         s.push(intervals[i]); //Non overlapping intervals
      }

      else if (temp.end < intervals[i].end){
         temp.end = intervals[i].end; //Overlapping
         s.pop();
         s.push(temp);
      }
   }

   //Print the finally merged intervals
   cout << "Intervals after merging:\n";

   while(!s.empty()){
      interval p = s.top();
      cout << "[" << p.start << "," << p.end << "]" << " ";
      s.pop();
   }

   cout << endl;

   return;
}

void TestCase1()
{
   interval intvls[] = { {1,3},{7,9},{4,6},{10,13} };
   vector<interval> intervals(intvls, intvls+4);        
   mergeIntervals(intervals);

}

int main(){
   
   TestCase1();
   return 0;
}
