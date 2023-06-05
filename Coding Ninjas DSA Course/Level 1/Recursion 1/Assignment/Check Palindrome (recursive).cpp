int len(char s[]) {
	int cnt = 0;
	while(s[cnt]!='\0') {
		cnt++;
	}

	return cnt;
}

bool helper(char s[], int si, int ei) {
	if(si==ei) {
		return true;
	}

	if(s[si]!=s[ei]) {
		return false;
	}

	if(si<ei+1) {
		return helper(s, si+1, ei-1);
	}

	return true;
}

bool checkPalindrome(char s[]) {
	int size = len(s);
	if(size==0 || size==1) {
		return true;
	}

	return helper(s, 0, size-1);

}
