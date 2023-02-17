/*
    Time Complexity - O(n*n)
    Space Complexity - O(n)
*/

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> prev(n+1, 0), curr(n+1, 0);
        
        for(int i=0; i<=n; i++) {
            prev[i] = price[0]*i;
        }
        
        for(int idx=1; idx<n; idx++) {
            for(int N=0; N<=n; N++) {
                int notTaken = prev[N];
                int taken = 0;
        
                int rodLength = idx+1;
                if(N-rodLength >= 0) {
                    taken = price[idx] + curr[N-rodLength];   
                }
                
                curr[N] = max(notTaken, taken);
            }
            prev = curr;
        }
        
        return prev[n];
    }
};