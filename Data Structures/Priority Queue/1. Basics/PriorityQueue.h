#include <vector>

//Time Complexity - O(nlog(n))
//Space Complexity - O(n)
class PriorityQueue {
	vector<int> pq; 

public:
	bool isEmpty() {
		return pq.size()==0;
	}
	
	//Returns the size of priorityQueue - no of elements present
	int getSize() {
		return pq.size();
	}

	int getMin() {
		if(isEmpty()) {
			return 0; //Priority Queue is empty
		}

		return pq[0];
	}

	void insert(int data) {
		pq.push_back(data);

		int childIndex = pq.size()-1;

		while(childIndex>0) {
			int parentIndex = (childIndex-1)/2;

			if(pq[childIndex]<pq[parentIndex]) {
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;
			} else {
				break;
			}

			childIndex = parentIndex;
		}
	}

	int removeMin() {
		if(isEmpty()) {
			return 0; //Priority Queue is empty
		}

		int ans = pq[0];
		pq[0] = pq[pq.size()-1];
		pq.pop_back();

		//Down-heapify

		int parentIndex = 0;
		int leftChildIndex = (2*parentIndex) + 1;
		int rightChildIndex = (2*parentIndex) + 2;

		//Used leftChildIndex here as there would be no right child unless there is a left child.
		while(leftChildIndex < pq.size()) {
			int minIndex = parentIndex;
			if(pq[minIndex] > pq[leftChildIndex]) {
				minIndex = leftChildIndex;
			}

			if(pq[minIndex] > pq[rightChildIndex] && rightChildIndex<pq.size()) {
				minIndex = rightChildIndex;
			}

			//If we reach at the proper place
			if(minIndex==parentIndex) {
				break;
			}

			int temp = pq[minIndex];
			pq[minIndex] = pq[parentIndex];
			pq[parentIndex] = temp;

			parentIndex = minIndex;
			leftChildIndex = (2*parentIndex) + 1;
			rightChildIndex = (2*parentIndex) + 2;
		}

		return ans;
	}
};