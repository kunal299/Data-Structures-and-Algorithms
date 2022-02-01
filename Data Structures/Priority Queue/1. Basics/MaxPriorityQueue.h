#include <vector>

class PriorityQueue{
	vector<int> pq;
public: 
	bool isEmpty() {
		return pq.size()==0;
	}

	int getSize() {
		return pq.size();
	}

	int getMax() {
		if(isEmpty()) {
			return 0;
		}
		return pq[0];
	}

	void insert(int element) {
		pq.push_back(element);

		int childIndex = pq.size()-1;

		while(childIndex>0) {

			int parentIndex = (childIndex-1)/2;

			if(pq[parentIndex] < pq[childIndex]) {
				int temp = pq[parentIndex];
				pq[parentIndex] = pq[childIndex];
				pq[childIndex] = temp;
			} else {
				break;
			}

			childIndex = parentIndex;
		}
	}

	int removeMax() {
		int ans = pq[0];

		pq[0] = pq[pq.size()-1];
		pq.pop_back();

		int parentIndex = 0;
		int leftChildIndex = (2*parentIndex) + 1;
		int rightChildIndex = (2*parentIndex) + 2;

		while(leftChildIndex < pq.size()) {
			int minIndex = parentIndex;

			if(pq[minIndex] < pq[leftChildIndex]) {
				minIndex = leftChildIndex;
			}

			if(pq[minIndex] < pq[rightChildIndex] && rightChildIndex<pq.size()) {
				minIndex = rightChildIndex;
			}

			if(parentIndex==minIndex) {
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