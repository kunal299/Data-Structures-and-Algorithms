/*
	Time Complexity - O(n)
	Space Complexity - O(n) 
*/

//Using Tabulation(Bottom-Up Approach)
int fibo(int n, vector<int> &dp) {
	dp[0] = 0, dp[1] = 1;

	for(int i=2; i<=n; i++) {
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];
}