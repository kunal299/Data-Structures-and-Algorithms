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
			}

			childIndex = parentIndex;
		}



	}

};