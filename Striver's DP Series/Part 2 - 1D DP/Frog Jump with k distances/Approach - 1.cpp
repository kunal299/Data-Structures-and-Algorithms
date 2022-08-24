/*
	Time Complexity - O(n*k)
	Space Complexity - O(n) 
*/

int helper(int idx, int k, vector<int> &v) {
	if(idx==0) return 0;

	int jumpCost = INT_MAX;
	for(int i=0; i<k; i++) {
		if(idx - (i+1) >= 0) {
			jumpCost = min(jumpCost, helper(idx - (i+1), k, v) + abs(v[idx] - v[idx-(i+1)]));
		}
	}

	return jumpCost;
}

void solve() {
	
	int n, k; cin>>n>>k;
	vector<int> v(n);
	for(auto &it: v) {
		cin>>it;
	}

	cout<<helper(n-1, k, v)<<nline;

}
