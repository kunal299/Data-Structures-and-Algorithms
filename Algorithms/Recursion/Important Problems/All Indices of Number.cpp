/*
All Indices of Number

Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. 
Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.

Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x

Output Format :
indexes where x is present in the array (separated by space)

Constraints :
1 <= N <= 10^3

Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4
*/

//Time Complexity - O(n)
//Space Complexity - O(1)
int allIndexes(int input[], int size, int x, int output[]) {
	//Base Case 
	//If the input array is empty, then simply return 0 which basically means that
	//the element would be not there as the size is 0.
	if(size==0) {
		return 0;
	}

	//Recursive call for rest of the array
	int ans = allIndexes(input+1, size-1, x, output);

	/*
	  Updating each value of output array by 1 as 
	  recursion will return the index value 1 less than the original value
	  Eg: Input Array - 9 8 10 8 8, x = 8
	  Now, we would handle the first value, but the rest is handled by recursion.
	  So, 8 10 8 8 will be handled to recursion.
	  For recursion, the index will start from 0 again.
	  Indexes: 0 1 2 3 
	  As x=8 is present at 0, 2 and 3 index, it will add 0, 2 and 3 to the output array, 
	  but in original array, there indexes are 1, 3, 4
	*/  
	for(int i=0; i<ans; i++) {
		output[i] += 1;
	}

	//If the first value which is handled by us is equal to x, 
	//then we have to add it to the output array.
	//So, for that we need to shift the elements of output array by one position, 
	//to insert the index value 0 in the beginning of the output array.
	if(input[0]==x) {
		for(int i=ans-1; i>=0; i--) {
			output[i+1] = output[i];
		}
		output[0] = 0;

		//Incrementing the size of output array by 1 as one more element is added to it.
        ans++;
	}

	return ans;
}