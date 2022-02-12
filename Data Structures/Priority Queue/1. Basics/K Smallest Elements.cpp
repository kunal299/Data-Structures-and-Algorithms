#include <iostream>
#include <queue>
using namespace std;

void KSmallestElements(int input[], int n, int k) {
	priority_queue<int>  pq;
	for(int i=0; i<k; i++) {
		pq.push(input[i]);
	}

	for(int i=k; i<n; i++) {
		if(input[i]<pq.top()) {
			pq.pop();
			pq.push(input[i]);
		}
	}

	while(k--) {
		cout<<pq.top()<<endl;
		pq.pop();
	}
}

int main() {
	int input[] = {2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6};
	int k = 4;
	KSmallestElements(input, 13, k);
}