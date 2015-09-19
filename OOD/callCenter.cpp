/*
 * Author: Khushboo Tekchandani
 * Call center with 3 ranks of employees
 * CTCI ch 8, question 2
 */

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Caller;
class Call;

class Employee{
   protected:
      int id_;
      Call *curcall_ = NULL;
      string name_;
      int rank_;
      // rank 0 - respondent
      // rank 1 - manager
      // rank 2 - director
   public:
      //Constructor
      Employee();
      Employee (int id, string name, int rank) : id_(id), name_(name), rank_(rank)
         {curcall_ = NULL;};

      //Other member functions
      void receiveCall(int call);
      void escalateCall(int call);
      bool isFree() {return curcall_ == NULL;};
      int getRank() {return rank_;};
      int getId() {return id_;};
      string getName() {return name_;};
};

class Caller{

   protected:
      string Name;
      string add;
      int phone;
    public:
      string getCallerName();
      string getadd();
      int getphone();
};

class Call{
   protected:
      int callid;
      Caller caller_;
      int rank; // Min rank who can handle this
      Employee *handler;

   public:
      Call();
      Call(int id, Caller c) : callid(id), caller_(c){
         rank = 0;
         handler = NULL;
      }

      void setHandler(Employee *e){handler = e;};
      void setRank(int r) {rank = r;};
};

class callHandler{
   
   protected:
      vector<Employee> respondents;
      vector<Employee> managers;
      vector<Employee> directors;
      vector<Call> calls;

   public:
      Employee gethandlerForCall(Call call){
         //find available employee inf respondents and assign it the call 
      }

      void dispatchCall(Call call){
         // Assign call to Employee.
      };


};

int main(){

   Employee *e1 = new Employee(1,"abc",0);
   cout << "Employee name: " << e1->getName() << endl;
}
