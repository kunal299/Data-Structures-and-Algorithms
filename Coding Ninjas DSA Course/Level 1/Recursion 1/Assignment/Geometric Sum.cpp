double helper(int k) {
	if(k==0) {
		return 1;
	}

	return 2*helper(k-1);
}

double geometricSum(int k) {
	if(k<0) {
		return 0;
	}

	return 1/helper(k) + geometricSum(k-1);
}