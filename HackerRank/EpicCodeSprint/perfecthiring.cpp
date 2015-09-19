/*-----------------------------------------------------------------------------
 * Author: Khushboo Tekchandani
 * Hacker Rank Epic Code Sprint
 * Perfect Hiring Problem
-----------------------------------------------------------------------------*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int num, x;
    long patience;
    cin >> num >> patience >> x;

    long scores[num];
    int i, id;
    long currentmax, rating;
    currentmax = 0;

    for (i=0; i<num; i++){
      cin >> scores[i];
    }

    for (i=0; i<num; i++){
      
         if ((patience-(i*x)) <= 0)
            break;
         rating = scores[i]*(patience-(i*x));
         if (rating > currentmax){
            currentmax = rating;
            id = i;
         }
    }

    cout << id+1 << endl;


    return 0;
}

