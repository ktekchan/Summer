/*
 * Khushboo Tekchandani
 * Online Reader System
 * Assumptions:
 *    1. Has books, one active user at a time, one active book at a time
 *    2. Search for a book
 *    3. Manage users
 *    4. Change pages etc
 */

#include <iostream>
#include <map>
#include <cstdlib>
#include <string>

using namespace std;

class Book{

   protected:
      long id_;
      string details_;
   public:
      Book(long id, string det) : id_(id), details_(det) {};

      //getters and setters
      long getId(){return id_;}
      string getDetails() {return details_;}

      void setId(long id) {id_ = id;}
      void setDetails(string det) {details_ = det;}
};

class Library{

   protected:
      map<long,Book*> books;
    public:
      Library();

      // Add a book to the library
      void addBook(long id, string details){

         if(books.find(id)!=books.end()){
            return;
         }
         Book *b = new Book(id,details);
         books.insert(pair<long,Book*>(id,b));
         return;
      }

      // Remove a book from the library
      bool removeBook(Book *b){
         if(books.find(b->getId())!=books.end()){
            books.erase(books.find(b->getId()));
            return true;
         }

         return false;
      }

      // Find a book from the library
      Book* findBook(long id){
         if(books.find(id)!=books.end()){
            return books.find(id)->second;
         }
         return NULL;
      }
};

class User{
   protected:
      long uid_;
      string name;
   public:
      User(long id, string n) : uid_(id), name(n){};
      //getters and setters
      long getUid() {return uid_;}
      string getName() {return name;}

      void setUid(long id) {uid_ = id;}
      void setName(string nm) {name = nm;}
};

class UserManager{
   protected:
      map<long,User*> users;
   public:

      // Add a user
      void addUser(long id, string name){
         if(users.find(id)!=users.end()){
            User *u = new User(id,name);
            users.insert(pair<long,User*>(id, u));
         }
         return;
      }

      // Remove a user
      bool removeUser(User *u){
         if(users.find(u->getUid())!=users.end()){
            users.erase(users.find(u->getUid()));
            return true;
         }
         return false;
      }

      // Find a user
      User* findUser(long id){
         return users.find(id)->second;
      }
};

class Display{
   protected:
      User *activeU;
      Book *activeBook;
      int pg;
   public:

     Display(User *u, Book *b, int page): activeU(u), activeBook(b), pg(page){}
     // Display active user
     void showUser(){
      cout << "Current user is " << activeU->getName() << endl;
      return;
     }

     // Display active book
     void showBook(){
      cout << "Active book is " << activeBook->getDetails() << endl;
      return;
     }

     // Move page forward
     void movePgFwd(){
      pg++;
     }

     // Move page back
     void movePgBk(){
      if(pg!=0)
         pg--;
     }
};

class OnlineReader{
   protected:
      Library *lib;
      UserManager *umanager;
      Display *display;
   public:
      OnlineReader(Library *l, UserManager *um, Display *d):lib(l), 
         umanager(um), display(d){}; 

      //getters and setters
      Library* getLib(){
         return lib;
      }

      UserManager* getUmanager(){
         return umanager;
      }

      Display* getDisplay(){
         return display;
      }

      void setLib (Library *l){
         lib = l;
      }

      void setUmanager (UserManager *um){
         umanager = um;
      }

      void setDisplay (Display *d){
         display = d;
      }
            
};

int main(){
   return 0;
}
