#include "bits/stdc++.h"
using namespace std;

//Time Complexity - O(n)
//Space Complexity - O(n)
void printIntersection(int arr1[], int arr2[], int n, int m) {
	unordered_map<int, int> mp;
	for(int i=0; i<n; i++) {
		mp[arr1[i]]++;
	}

	for(int i=0; i<m; i++) {
		if(mp.find(arr2[i]) != mp.end()) {
			cout<<arr2[i]<<endl;
		}

		if(mp[arr2[i]] > 1) {
			--mp[arr2[i]];
		} else {
			mp.erase(arr2[i]);
		}
	}
}

int main() {
	int arr1[] = {2, 6, 1, 2};
	int arr2[] = {1, 2, 3, 4, 2};

	printIntersection(arr1, arr2, 4, 5);
}