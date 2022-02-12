#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int> > pq;
	pq.push(12);
	pq.push(122);
	pq.push(112);
	pq.push(13);
	pq.push(16);

	cout<<"Size: "<<pq.size()<<endl;
	cout<<"Top: "<<pq.top()<<endl;

	while(!pq.empty()) {
		cout<<pq.top()<<endl;
		pq.pop();
	}
}