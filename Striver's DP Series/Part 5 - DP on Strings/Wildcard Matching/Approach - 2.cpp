/*
    Time Complexity - O(M*N)
    Space Complexity - O(M*N)
*/

class Solution {
public:
    bool isAllStars(string &p, int j) {
        for(int i=0; i<=j; i++) {
            if(p[i] != '*') return false;
        }
        
        return true;
    }
    
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        vector<vector<bool>> dp(m+1, vector<bool> (n+1, false));

        //If s is exhausted but p is not
        for(int j=1; j<=n; j++) {
            dp[0][j] = isAllStars(p, j-1);
        }
        
        //If s is exhausted and p is also exhausted
        dp[0][0] = true;
        
        //If s is not exhausted but p is exhausted
        for(int i=1; i<=m; i++) {
            dp[i][0] = false;
        }

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {

                if(s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    if(p[j-1] == '*') {
                        dp[i][j] = (dp[i][j-1]  || dp[i-1][j]);
                    } else {
                        dp[i][j] = false;
                    }
                }

            }
        }

        return dp[m][n];
    }
};