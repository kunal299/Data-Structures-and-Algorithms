#include <iostream>
#include <queue>
using namespace std;

//Time Complexity -> TC1 + TC2 + TC3 -> (n+k)logk
//Generally, the value of n is big whereas the value of k is smaller than it.
//So, if we assume that k is negligible, then TIME COMPLEXITY -> nlogk ~ O(n)
void kSortedArray(int input[], int n, int k) {
	priority_queue<int> pq;
	
	//TC -> 1 : klogk
	for(int i=0; i<k; i++) {
		pq.push(input[i]);
	}

	int j = 0;

	//TC -> 2 : (n-k)logk
	for(int i=k; i<n; i++) {
		input[j] = pq.top();
		pq.pop();
		pq.push(input[i]);
		j++;
	}

	//TC -> 3: klogk 
	while(!pq.empty()) {
		input[j] = pq.top();
		pq.pop();
		j++;
	}
}

int main() {
	int input[] = {10, 12 , 6 , 7, 9};
	int k = 3;
	kSortedArray(input, 5, k);
	for(int i=0; i<5; i++) {
		cout<<input[i]<<" ";
	}
}