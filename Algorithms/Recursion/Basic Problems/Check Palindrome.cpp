/*
Check Palindrome (recursive)

Check whether a given String S is a palindrome using recursion. Return true or false.

Input Format :
String S

Output Format :
'true' or 'false'

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
racecar
Sample Output 1:
true

Sample Input 2 :
ninja
Sample Output 2:
false
*/
	
//Time Complexity - O(n)
//Space Complexity - O(n)

//Function used to find the length of the string 
int len(char s[]) {
	int cnt = 0;
	while(s[cnt]!='\0') {
		cnt++;
	}

	return cnt;
}

//Helper function used to check if the string is palindrome or not
bool helper(char s[], int si, int ei) {
	if(si==ei) {
		return true;
	}

	if(s[si]!=s[ei]) {
		return false;
	}

	//Recursively checking for the rest indices
	if(si<ei+1) {
		return helper(s, si+1, ei-1);
	}

	return true;
}

//Main Function
bool checkPalindrome(char s[]) {
	int size = len(s);

	//If size is 0 or 1, it means that it's already a palindrome
	if(size==0 || size==1) {
		return true;
	}
	
	return helper(s, 0, size-1);
}