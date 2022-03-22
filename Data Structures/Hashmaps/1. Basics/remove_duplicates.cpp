#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//Time Complexity - O(size)
vector<int> removeDuplicates(int *a, int size) {
	vector<int> output;
	unordered_map<int, bool> mp;
	for(int i=0; i<size; i++) {
		if(mp.count(a[i])>0) {
			continue;
		}
		mp[a[i]] = true;
		output.push_back(a[i]);
	}

	return output;
}

int main() {
	int arr[] = {1, 2, 3, 2, 1, 5, 4, 1, 3};

	vector<int> ans = removeDuplicates(arr, 9);

	for(int i=0; i<ans.size(); i++) {
		cout<<ans[i]<<endl;
	}
}