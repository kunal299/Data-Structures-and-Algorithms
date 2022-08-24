/*
	Time Complexity - O(n*k)
	Space Complexity - O(n)
*/

int helper(int idx, int k, vector<int> &v, vector<int> &dp) {
	dp[0] = 0;

	for(int i=1; i<=idx; i++) {
		int jumpCost = INT_MAX;
		for(int j=1; j<=k; j++) {
			if(i - j >= 0) {
				jumpCost = min(jumpCost, dp[i-j] + abs(v[i] - v[i-j]));
			}
		}
		dp[i] = jumpCost;
	}

	return dp[idx];
}

void solve() {
	
	int n, k; cin>>n>>k;
	vector<int> v(n);
	for(auto &it: v) {
		cin>>it;
	}

	vector<int> dp(n, -1);
	cout<<helper(n-1, k, v, dp)<<nline;

}