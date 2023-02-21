/*
    Time Complexity - O(m*n)
    Space Complexity - O(m*n)
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
    
        for(int idx1=0; idx1<=m; idx1++) {
            dp[idx1][0] = 0;
        }

        for(int idx2=0; idx2<=n; idx2++) {
            dp[0][idx2] = 0;
        }

        for(int idx1=1; idx1<=m; idx1++) {
            for(int idx2=1; idx2<=n; idx2++) {

                if(text1[idx1-1] == text2[idx2-1]) {
                    dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
                } else {
                    dp[idx1][idx2] = max(dp[idx1-1][idx2], dp[idx1][idx2-1]);
                }

            }
        }

        return dp[m][n];
    }
};