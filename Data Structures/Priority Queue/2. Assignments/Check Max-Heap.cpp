#include <iostream>
using namespace std;

bool isMaxHeap(int input[], int n) {

	int parentIndex = 0;
	int leftChildIndex = 2*parentIndex + 1;
	int rightChildIndex = 2*parentIndex + 2;

	while(leftChildIndex<n) {
		if(input[parentIndex]<input[leftChildIndex] || input[parentIndex]<input[rightChildIndex]) {
		return false;
	} 
	}

	if(parentIndex<input[leftChildIndex] || parentIndex<input[rightChildIndex]) {
		return false;
	} 
}

int main() {
	int input[] = {42, 20, 28, 6, 14, 11, 9, 4};
	if(isMaxHeap(input, n)) {
		cout<<"true"<<endl;
	} else {
		cout<<"false"<<endl;
	}
}