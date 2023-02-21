/*
    Time Complexity - O(m*n)
    Space Complexity - O(m*n) + O(m+n)
*/

class Solution {
public:
    int lcsHelper(int idx1, int idx2, string &text1, string &text2, vector<vector<int>> &dp) {
        if(idx1<0 || idx2<0) return 0;

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(text1[idx1]==text2[idx2]) {
            return dp[idx1][idx2]=1 + lcsHelper(idx1-1, idx2-1, text1, text2, dp);
        } 

        return dp[idx1][idx2]=max(lcsHelper(idx1-1, idx2, text1, text2, dp), lcsHelper(idx1, idx2-1, text1, text2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m, vector<int> (n, -1));
        return lcsHelper(m-1, n-1, text1, text2, dp);
    }
};