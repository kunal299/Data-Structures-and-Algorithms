/*	
	Time Complexity - O(m*n)
	Space Complexity - O(m*n)
*/

#include <bits/stdc++.h> 
int lcs(string &str1, string &str2){
	int m = str1.size();
	int n = str2.size();

	vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

	int ans = 0;
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {

			if(str1[i-1]==str2[j-1]) {
				int val = 1 + dp[i-1][j-1];
				dp[i][j] = val;
				ans = max(ans, val);
			} else {
				dp[i][j] = 0;
			}

		}
	}

	return ans;
}