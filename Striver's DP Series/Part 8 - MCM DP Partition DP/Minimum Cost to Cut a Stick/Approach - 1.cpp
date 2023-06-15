/*
    Time Complexity - O(N*N)
    Space Complexity - O(N)
*/

class Solution {
public:
    int helper(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mini = 1e9;
        for(int k=i; k<=j; k++) {
            int cost = cuts[j+1] - cuts[i-1] + helper(i, k-1, cuts, dp) + helper(k+1, j, cuts, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c+1, vector<int> (c+1, -1));

        return helper(1, c, cuts, dp);
    }
};