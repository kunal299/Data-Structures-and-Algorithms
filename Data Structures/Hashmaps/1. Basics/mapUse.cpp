#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	unordered_map<string, int> ourMap;

	/* ***** insert ***** */
	//Method 1
	pair<string, int> p("abc", 1);
	ourMap.insert(p);

	//Method 2
	ourMap["def"] = 2;


	/* ***** find or access ***** */
	//Method 1
	cout<<ourMap["abc"]<<endl;
	
	//Method 2
	cout<<ourMap.at("abc")<<endl;

	//Difference between Method1 and Method2
	cout<<ourMap.at("ghi")<<endl; //This will throw an exception saying that key not found
	
	cout<<ourMap["ghi"]<<endl; //Square bracket is a little bit weird. If the key is not found, 
							   //it creates a key and assign 0 to it.

	
	/* ***** Check Presence ***** */
	if(ourMap.count("ghi")>0) {
		cout<<"ghi is present"<<endl;
	}

	
	/* ***** Check Size ***** */
	cout<<"size: "<<ourMap.size()<<endl;

	
	/* ***** Erase ***** */
	ourMap.erase("ghi");
}