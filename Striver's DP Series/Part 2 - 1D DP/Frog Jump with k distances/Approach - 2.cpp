/*
	Time Complexity - O(n*k)
	Space Complexity - O(n)

*/

int helper(int idx, int k, vector<int> &v, vector<int> &dp) {
	if(idx==0) return 0;
	if(dp[idx]!=-1) return dp[idx];

	int jumpCost = INT_MAX;
	for(int i=0; i<k; i++) {
		if(idx - (i+1) >= 0) {
			jumpCost = min(jumpCost, helper(idx - (i+1), k, v, dp) + abs(v[idx] - v[idx-(i+1)]));
		}
	}

	return dp[idx] = jumpCost;
}

void solve() {
	
	int n, k; cin>>n>>k;
	vector<int> v(n);
	for(auto &it: v) {
		cin>>it;
	}

	vector<int> dp(n, -1);
	cout<<helper(n-1, k, v, dp)<<"\n";
}