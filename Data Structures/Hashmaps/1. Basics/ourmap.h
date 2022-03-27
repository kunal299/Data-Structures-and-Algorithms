#include <string>
using namespace std;

//Class for Linked List
template <typename V>
class MapNode { 
public: 
	string key;
	V value;
	MapNode* next;

	//Constructor to assign values
	MapNode(string key, V value) { 
		this->key = key;
		this->value = value;
		next = NULL;
	}	

	//Destructor to delete the node
	~MapNode() {
		delete next;
	}
};

/*Time complexity is on an average O(1) for insertion, deletion and search operations each*/

template <typename V>
class ourmap {
public: 
	// 2-D bucket array to store the head pointers of the linked list corresponding to each index
	MapNode<V>** buckets;
	
	int count; //to store the size
	int numBuckets; //to store the number of buckets for compression function
	
	ourmap() {
		count = 0;
		numBuckets = 5;
		buckets = new MapNode<V>* [numBuckets]; //dynamically allocated
		for(int i=0; i<numBuckets; i++) {
			buckets[i] = NULL;
		}
	}

	~ourmap() {
		//Firstly deleting each linked list
		for(int i=0; i<numBuckets; i++) {
			delete buckets[i];
		}

		//Then deleting the total bucket 
		delete [] buckets;
	}

	//Returns the size of the map
	int size() {
		return count;
	}

	//Returns the value of the key
	V getValue(string key) {
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		
		//If key is found
		while(head!=NULL) {
			if(head->key == key) {
				return head->value;
			}
			head = head->next;
		}

		//If key is not found
		return 0;
	}

private:
	//Returns the bucket index of the string 
	int getBucketIndex(string key) {
		//Part 1: Hash Code
		int hashCode = 0;
		int currentCoeff = 1;

		// using “abcd” = (‘a’ * p^3) + (‘b’ * p^2) + (‘c’ * p^1) + (‘d’ * p^0) as our hash code
		for(int i=key.length()-1; i>=0; i--) {
			hashCode += (key[i] * currentCoeff);
			hashCode = hashCode % numBuckets; 

			currentCoeff *= 37; //taking p = 37 (any prime number)
			currentCoeff = currentCoeff % numBuckets;
		}

		//Part 2: Compression Function
		return hashCode % numBuckets;
	}

	void rehash() {
		MapNode<V>** temp = buckets;
		buckets = new MapNode<V>* [2*numBuckets];

		for(int i=0; i<2*numBuckets; i++) {
			buckets[i] = NULL;
		}

		int oldBucketCount = numBuckets;
		numBuckets *= 2; //updating new size(doubling it)
		count = 0;

		for(int i=0; i<oldBucketCount; i++) {
			MapNode<V>* head = temp[i];
			
			while(head!=NULL) {
				string key = head->key;
				V value = head->value;

				//Inserting each value of old bucket into the new one
				insert(key, value);

				head = head->next;
			}
		}

		//Deleting the old bucket
		for(int i=0; i<oldBucketCount; i++) {
			MapNode<V>* head = temp[i];
			delete head;
		}

		delete [] temp;
	}

public:

	double getLoadFactor() {
		return (1.0 * count)/ numBuckets;
	}

	//Inserts the key with its value in the map
	void insert(string key, V value) {
		
		//Passing key through hash function to get the index
		int bucketIndex = getBucketIndex(key);

		MapNode<V>* head = buckets[bucketIndex];

		//Checking whether the key is already present in the map
		while(head!=NULL) {

			//If present, then just update it
			if(head->key == key) {
				head->value = value;
				return;
			}
			head = head->next;
		}

		//Otherwise, create a new node and attach it
		head = buckets[bucketIndex];
		MapNode<V>* node = new MapNode<V> (key, value);
		node->next = head;
		buckets[bucketIndex] = node;
		count++;

		//Now, we will check the load factor after insertion
		double loadFactor = (1.0 * count) / numBuckets;
		if(loadFactor > 0.7) {
			rehash(); //We will rehash.
		}

		return;
	}

	//Removes the key and returns the key value
	V remove(string key) {
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		MapNode<V>* prev = NULL;
		
		while(head!=NULL) {
			if(head->key == key) {
				if(prev==NULL) {
					buckets[bucketIndex] = head->next;
				} else {
					prev->next = head->next;
				}
				V value = head->value;

				//before calling delete over it, in order to avoid complete linked list deletion, 
				//we have to assign it's next to NULL
				head->next = NULL;
				
				delete head;
				count--;
				return value;
			}
			prev = head;
			head = head->next;
		}
 
		return 0; //means that value not found
	}
};