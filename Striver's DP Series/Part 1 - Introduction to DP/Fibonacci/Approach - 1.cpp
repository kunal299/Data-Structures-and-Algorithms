/*
	Time Complexity - O(n)
	Space Complexity - O(n) + O(n) ~ O(n)
*/

//Using Memoization(Top-Down Approach)
int fibo(int n, vector<int> &dp) {
	if(n<=1) {
		return n;
	}

	if(dp[n]!=-1) return dp[n];

	return dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
}