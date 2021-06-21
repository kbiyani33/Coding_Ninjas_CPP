/*
Functions needed in map:
    1. insert(key k, value v)
    2. getValue(key k)
    3. deleteKey(key k)

    How can we make this ?
        1. Use a Linked List with each node having not data but key and value.
            All 3 operations will be done in O(n). Why is insert having O(1)? Because we have to first search if the key is pre-existing.
        
        2.  Using a balanced BST (with height = log N)
            All 3 operations will be done in O(lon N). Using BST, we get the map
        
        3. Using hash tables we can get the 3 functions in O(1). We shall see this later.


        
        
*/

#include<iostream>
#include<unordered_map>
#include<string>
#include<map>
using namespace std;

int main(){
    /*
    In c++ we have map and unordered_map.
    map is implemented using BST
    unordered_map is implemented using Hash Table
    */
   unordered_map<string, int> ourMap;
   // insert
   pair<string, int> p("abc", 1);
   ourMap.insert(p); // One way to insert
   ourMap["abcd"] = 1;

   // access
   cout << ourMap["abc"] << endl; // Using square bracket
   // cout << ourMap.at("def") << endl;
   cout << ourMap["def"] << endl; 
    // This is the second way of accessing. 
   // Square bracket will not give an error if the key doesn't exist. If the key doesn't exist it will insert the key with the value = default value of the datatype chosen.

   // using .at() we get an exception so it's much more preferred.
   // So how will be check if a key exists or not ? Using ourmap.count

   if(ourMap.count("def") > 0){

       cout << "ghi is present with value " << ourMap.at("def") << endl;
   }
   // We also have the size function. It returns the total number of keys.

   cout << ourMap.size() << endl;

   // Remove the key
   ourMap.erase("def");
   if(ourMap.count("def") > 0){

       cout << "def is present with value " << ourMap.at("def") << endl;
   }
   cout << ourMap.size() << endl;
   return 0;
}
