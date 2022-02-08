#include <iostream>
using namespace std;

void heapSort(int arr[], int n) {
	//Build the head in the input array
	for(int i=1; i<n; i++) {
		// int i = 1; 
		int childIndex = i;
		// int parentIndex = (childIndex-1)/2;
 
		while(childIndex>0) {
			int parentIndex = (childIndex-1)/2;

			if(arr[childIndex]<arr[parentIndex]) {
				swap(arr[childIndex], arr[parentIndex]);
			} else {
				break;
			}

			childIndex = parentIndex;
		}	 
	}

	int size = n;
	// int temp = arr[0];
	while(size>1) {
		swap(arr[0], arr[size-1]);

		size--;

		int parentIndex = 0;
		int leftChildIndex = (2*parentIndex) + 1;
		int rightChildIndex = (2*parentIndex) + 2;

		//Used leftChildIndex here as there would be no right child unless there is a left child.
		while(leftChildIndex < size) {
			int minIndex = parentIndex;
			if(arr[minIndex] > arr[leftChildIndex]) {
				minIndex = leftChildIndex;
			}

			if(arr[minIndex] > arr[rightChildIndex] && rightChildIndex<size) {
				minIndex = rightChildIndex;
			}

			//If we reach at the proper place
			if(minIndex==parentIndex) {
				break;
			}

			int temp = arr[minIndex];
			arr[minIndex] = arr[parentIndex];
			arr[parentIndex] = temp;

			parentIndex = minIndex;
			leftChildIndex = (2*parentIndex) + 1;
			rightChildIndex = (2*parentIndex) + 2;
		}
	}
	
}

int main() {
	int arr[5] = {0, 1, 5, 8, 2};
	heapSort(arr, 5);

	for(int i=0; i<5; i++) {
		cout<<arr[i]<<" ";
	}
}