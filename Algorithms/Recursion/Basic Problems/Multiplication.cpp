/*
Multiplication (Recursive)

Given two integers M & N, calculate and return their multiplication using recursion. 
You can only use subtraction and addition for your calculation. No other operators are allowed.

Input format :
Line 1 : Integer M
Line 2 : Integer N

Output format :
M x N

Constraints :
0 <= M <= 1000
0 <= N <= 1000

Sample Input 1 :
3 
5
Sample Output 1 :
15

Sample Input 2 :
4 
0
Sample Output 2 :
0
*/

//Time Complexity - O(n)
//Space Complexity - O(n)
//where n is the smaller of the two numbers we need to multiply
int multiplyNumbers(int m, int n) {
    if(n>m) {
	return multiplyNumbers(n, m);
    }

    if(n==0 || m==0) {
        return 0;
    }
    
    return m + multiplyNumbers(m, n-1);
}
