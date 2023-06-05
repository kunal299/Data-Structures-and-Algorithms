int countZeros(int n) {
    if(n==0) {
		return 1;
	} else if(n<=9) {
		return 0;
	}

	if(n%10==0) {
		return 1 + countZeros(n/10);
	} else {
		return countZeros(n/10);
	}

}