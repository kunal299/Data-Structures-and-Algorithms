/*
    Time Complexity - O(M*N)
    Space Complexity - O(M*N)
*/

class Solution {
public:
    int lcs(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        for(int i=0; i<=m; i++) {
            dp[i][0] = 0;
        }

        for(int j=0; j<=n; j++) {
            dp[0][j] = 0;
        }

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {

                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }

            }
        }

        return dp[m][n];
    }

    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());

        return s.length()-lcs(t, s);
    }
};