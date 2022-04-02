/*
Extract Unique characters

Given a string S, you need to remove all the duplicates. 
That means, the output string should contain each character only once. 
The respective order of characters should remain same, as in the input string.

Input format:
The first and only line of input contains a string, that denotes the value of S.

Output format :
The first and only line of output contains the updated string, as described in the task.

Constraints :
0 <= Length of S <= 10^8
Time Limit: 1 sec

Sample Input 1 :
ababacd
Sample Output 1 :
abcd

Sample Input 2 :
abcde
Sample Output 2 :
abcde
*/

#include <iostream>
#include <unordered_set>
using namespace std;

//Time Complexity - O(n)
//Space Complexity - O(1)
string uniqueChar(string str) {
	unordered_set<char> st;
	string ans = "";

	for(int i=0; i<str.length(); i++) {
		if(st.find(str[i]) == st.end()) {
			ans += str[i];
			st.insert(str[i]);
		}
	}

	return ans;
}

int main() {
	string s = "ababacd";
	cout<<uniqueChar(s)<<endl;

	return 0;
}