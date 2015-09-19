/*
 * Khushboo Tekchandani
 * Implement a hash table that uses chaining to handle collisions
 * Must store both key and value pairs instead of just values
 */
#include <iostream>
#include <utility>
#include <list>
#include <string>

using namespace std;

class Hash{
   protected:
      int capacity;
      list <pair<int,string> > entries;
    public:
      Hash(int c, list<pair<int,string> > items) : capacity(c),entries(items) {}

      int hashCode(string key){
         return key.length();
      }

      void insert(string key, string val){
         int hashKey = hashCode(key);
         if (entries[hashKey] == NULL){
            entries[hashKey] = new list<pair<int, string> >();
         }
      }
};

int main(){}
