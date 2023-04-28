/*
    Time Complexity - O(M*N)
    Space Complexity - O(M*N)
*/

class Solution {
public:
    string scs(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();

        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

        for(int i=0; i<=m; i++) {
            dp[i][0] = 0;
        }

        for(int j=0; j<=n; j++) {
            dp[0][j] = 0;
        }

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                
                if(str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }

            }
        }

        int len = dp[m][n];
        int i = m; 
        int j = n;

        string ans = "";
        int idx = len - 1;
        while(i>0 && j>0) {
            if(str1[i-1] == str2[j-1]) {
                ans += str1[i-1];
                i--;
                j--; 
                idx--;
            } else if(dp[i - 1][j] > dp[i][j - 1]) {
                ans += str1[i-1];
                i--;
            } else {
                ans += str2[j-1];
                j--;
            }
        }

        while(i>0) {
            ans += str1[i-1];
            i--; 
        }

        while(j>0) {
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        
        return scs(str1, str2);
    }
};