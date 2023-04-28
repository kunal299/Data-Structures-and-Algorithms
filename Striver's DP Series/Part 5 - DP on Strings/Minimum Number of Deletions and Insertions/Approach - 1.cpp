/*
    Time Complexity - O(M*N)
    Space Complexity - O(M*N)
*/

#include <bits/stdc++.h> 

int lcs(string str, string ptr) {
    int m = str.length();
    int n = ptr.length();

    vector<vector<int>> dp(m+1, vector<int> (n+1, -1));

    for(int i=0; i<=m; i++) {
        dp[i][0] = 0;
    }

    for(int j=0; j<=n; j++) {
        dp[0][j] = 0;
    }
    
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {

            if(str[i-1] == ptr[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }

        }
    }

    return dp[m][n];
}

int canYouMake(string &str, string &ptr)
{
    int t = lcs(str, ptr);
    int m = str.length();
    int n = ptr.length();

    return (m-t) + (n-t);
}