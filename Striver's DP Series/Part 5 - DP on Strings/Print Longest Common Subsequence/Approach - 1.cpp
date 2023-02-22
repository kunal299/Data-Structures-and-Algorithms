/*
	Time Complexity - O(m*n)
	Space Complexity - O(m*n)
*/

void lcs(string s1, string s2) {
	int m = s1.size();
	int n = s2.size();

	vector<vector<int>> dp(m+1, vector<int> (n+1, -1));

	for(int i=0; i<=m; i++) {
		dp[0][i] = 0;
	}

	for(int j=0; j<=n; j++) {
		dp[j][0] = 0;
	}

	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			if(s1[i-1]==s2[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	int len = dp[m][n];
	int i = m;
	int j = n;

	string answer = "";
	for(int i=0; i<len; i++) {
		answer += "$";
	}

	while(i>0 && j>0) {
		if(s1[i-1]==s2[j-1]) {
			answer[len-1] = s1[i-1];
			--i;
			--j;
			--len;
		} else if(s1[i-1] > s2[j-1]) {
			--i;
		} else {
			--j;
		}
	}

	cout<<answer<<nline;
	return;
}