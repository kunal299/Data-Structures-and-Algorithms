/*
	Time Complexity - O(n)
	Space Complexity - O(1) 
*/

//Space Optimization
int fibo(int n) {
	int prev = 1, prev2 = 0;
	
	for(int i=2; i<=n; i++) {
		int curr = prev+prev2;
		prev2 = prev;
		prev = curr;
	}

	return prev;
}