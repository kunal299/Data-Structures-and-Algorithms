#include <iostream>
using namespace std;

//Time Complexity - O(2^n)
int fibo(int n) {
	if(n<=1) {
		return n;
	}

	int a = fib(n-1);
	int b = fib(n-2);
	return a+b;
}

//Time Complexity - O(n)
//This process is called Memoization. It is a top-down approach where we save our previous answers
//so that we can use it directly in the future. It drastically decreases the time complexity.
//Generally, it is recursive.
int fibo_helper(int n, int *ans) {
	if(n<=1) {
		return n;
	}

	//Check if output already exists
	if(ans[n] != -1) {
		return ans[n];
	}

	int a = fibo_helper(n-1, ans);
	int b = fibo_helper(n-2, ans);

	//Save the output for future use
	ans[n] = a+b;

	//Return the final output
	return ans[n];

}

int fibo_2(int n) {
	int *ans = new int[n+1];
	for(int i=0; i<n; i++) {
		ans[i] = -1;
	}
	return fibo_helper(n, ans);
}

//Time Complexity - O(n)
//Using Dynamic Programming - bottom-up approach
//Generally it is iterative.
int fibo_3(int n) {
	int *ans = new int[n+1];

	ans[0] = 0;
	ans[1] = 1;

	for(int i=2; i<=n; i++) {
		ans[i] = ans[i-1] + ans[i-2];
	}

	return ans[n];
}

int main() {

	int n; cin>>n;
	cout<<fibo(n)<<endl;

	return 0;
}