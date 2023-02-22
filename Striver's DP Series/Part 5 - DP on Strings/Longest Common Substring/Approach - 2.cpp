/*
	Time Complexity - O(m*n)
	Space Complexity - O(n)
*/

#include <bits/stdc++.h> 
int lcs(string &str1, string &str2){
	int m = str1.size();
	int n = str2.size();

	vector<int> prev(n+1, 0), curr(n+1, 0);

	int ans = 0;
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {

			if(str1[i-1]==str2[j-1]) {
				int val = 1 + prev[j-1];
				curr[j] = val;
				ans = max(ans, val);
			} else {
				curr[j] = 0;
			}

		}
		prev = curr;
	}

	return ans;
}