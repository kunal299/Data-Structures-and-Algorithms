#include <iostream>
using namespace std;

#include "MaxPriorityQueue.h"

int main() {
	PriorityQueue p;
	p.insert(100);
	cout<<p.getSize()<<endl;
	p.insert(123);
	cout<<p.getSize()<<endl;
	p.insert(12);
	p.insert(112);
	p.insert(121);
	p.insert(124);
	p.insert(14);

	while(!p.isEmpty()) {
		cout<<p.removeMax()<<" ";
	}
	cout<<endl;
}