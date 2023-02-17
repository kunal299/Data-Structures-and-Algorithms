/*
    Time Complexity - O(N*W)
    Space Complexity - O(W)
*/

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> prev(W+1, 0), curr(W+1, 0);
        
        for(int i=0; i<=W; i++) {
            prev[i] = (i/wt[0])*val[0];
        }
        
        for(int idx=1; idx<N; idx++) {
            for(int w=0; w<=W; w++) {
                int notPick = prev[w];
                int pick = 0;
                if(w-wt[idx] >= 0) {
                    pick = val[idx] + curr[w-wt[idx]];
                }
                
                curr[w] = max(notPick, pick);
            }
            prev = curr;
        }
        
        return prev[W];
    }
};