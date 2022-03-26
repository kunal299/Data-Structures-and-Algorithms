#include "bits/stdc++.h"
using namespace std;

int main() {
	//Imp fact: unordered_set is built using Hashtable while set is built using BST.


	//In the case of unordered maps
	unordered_map<string, int> ourmap;
	ourmap["abc"] = 1;
	ourmap["abc1"] = 2;
	ourmap["abc2"] = 3;
	ourmap["abc3"] = 4;
	ourmap["abc4"] = 5;
	ourmap["abc5"] = 6;

	unordered_map<string, int> :: iterator it = ourmap.begin();
	while(it != ourmap.end()) {
		cout<<"Key: "<<it->first<<" Value: "<<it->second<<endl;
		it++;
	}

	//find - returns the iterator of that element in the map
	unordered_map<string, int> :: iterator it2 = ourmap.find("abc");
 	
	//erase - It deletes the iterator where it is pointing
 	ourmap.erase(it2); //It will only delete the current iterator
 	ourmap.erase(ourmap.begin(), ourmap.end()); //It will delete the element from starting iterator to the end iterator

	//In the case of vectors
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int> :: iterator it1 = v.begin();
	while(it1 != v.end()) {
		cout<<*it1<<endl;
		it1++;
	}
}