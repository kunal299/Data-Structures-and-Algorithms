/*
    Time Complexity - O(N*K)
    Space Complexity - O(N)
*/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n+1, -1);
        dp[n] = 0;

        for(int idx=n-1; idx>=0; idx--) {
            int maxi = -1e9, maxAns = -1e9;
            int len = 0;
            for(int i=idx; i<min(idx+k, n); i++) {
                len++;
                maxi = max(maxi, arr[i]);
                int sum = (maxi * len) + dp[i+1];
                maxAns = max(maxAns, sum);
            }

            dp[idx]=maxAns;
        }

        return dp[0];
    }
};