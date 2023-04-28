/*
    Time Complexity - O(N*N)
    Space Complexity - O(N*N)
*/

class Solution {
public:
    int lcs(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        
        for(int i=0;i<=m;i++){
            dp[0][i] = 0;
        }
    
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s1[ind1-1]==s2[ind2-1])
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                else
                    dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
    
        return dp[n][m];
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t);
    }
};