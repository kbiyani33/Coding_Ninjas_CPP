#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main() {
	unordered_map<string, int> ourmap;
	ourmap["abc"] = 1;
	ourmap["abc1"] = 2;
	ourmap["abc2"] = 3;
	ourmap["abc3"] = 4;
	ourmap["abc4"] = 5;
	ourmap["abc5"] = 6;

	unordered_map<string, int>::iterator it = ourmap.begin(); // it will be a pointer to the beginning value
	while (it != ourmap.end()) // ourmap.end() will return the pointer to the memory location that is outside the map
    {
		cout << "Key : " << it->first << " Value: " << it->second << endl;
		it++;
	}

	// find
	unordered_map<string, int>::iterator it2 = ourmap.find("abc"); // find method will essentially return an iterator that's pointing to the element with the given key. We can access the elements after it using it++
	ourmap.erase(it2); // erase will also return an iterator. We can even erase in a group.
	

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int>::iterator it1 = v.begin(); // // it1 will be a pointer to the beginning value
	while (it1 != v.end()) {
		cout << *it1 << endl; // Since it's a pointer, we will print the value using *
		it1++;
	}
    // v.erase(v.begin(), v.end());
    // while (it1 != v.end()) {
	// 	cout << *it1 << endl; // Since it's a pointer, we will print the value using *
	// 	it1++;
	// }
}