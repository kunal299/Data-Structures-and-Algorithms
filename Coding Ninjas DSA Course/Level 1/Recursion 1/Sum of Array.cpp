int sum(int input[], int n) {
  if(n==1) {
    return input[0];
  }

  return input[0] + sum(input+1, n-1);
}