/*
    Time Complexity - O(N*K)
    Space Complexity - O(N) + O(N)
*/

class Solution {
public:
    int helper(int idx, int n, int k, vector<int> &arr, vector<int> &dp) {
        if(idx == n) return 0;

        if(dp[idx] != -1) return dp[idx];

        int maxi = -1e9, maxAns = -1e9;
        int len = 0;
        for(int i=idx; i<min(idx+k, n); i++) {
            len++;
            maxi = max(maxi, arr[i]);
            int sum = (maxi * len) + helper(i+1, n, k, arr, dp);
            maxAns = max(maxAns, sum);
        }

        return dp[idx]=maxAns;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n+1, -1);
        return helper(0, n, k, arr, dp);
    }
};