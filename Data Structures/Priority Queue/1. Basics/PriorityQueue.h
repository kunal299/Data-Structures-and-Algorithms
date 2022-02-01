#include<vector>

class PriorityQueue{
	vector<int> pq;
public: 
	PriorityQueue() {

	}

	bool isEmpty() {
		return pq.size()==0;
	}
	
	//Returns the size of priorityQueue - no of elements present
	int getSize() {
		return pq.size();
	}

	int getMin() {
		if(pq.isEmpty()) {
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
				swap(pq[childIndex], pq[parentIndex]);
			} else {
				break;
			}

			childIndex = parentIndex;
		}
	}

	int removeMin() {
		if(pq.isEmpty()) {
			return 0; //Priority Queue is empty
		}

		int ans = pq[0];
		int lastIndex = pq.size()-1;

		swap(pq[0], pq[lastIndex]);
		pq.pop_back();

		//down-heapify

		int parentIndex = 0;
		int leftChildIndex = (2*parentIndex) + 1;
		int rightChildIndex = (2*parentIndex) + 2;

		//Used leftChildIndex here as there would be no right child unless there is a left child.
		while(leftChildIndex < pq.size()) {
			int minIndex = 0;
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

			swap(pq[minIndex], pq[parentIndex]);

			parentIndex = minIndex;
			leftChildIndex = (2*parentIndex) + 1;
			rightChildIndex = (2*parentIndex) + 2;
		}

		return ans;		
	}

};