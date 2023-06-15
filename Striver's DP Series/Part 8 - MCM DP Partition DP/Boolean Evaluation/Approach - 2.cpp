/*
    Time Complexity - O((N*N*2)*N)
    Space Complexity - O(N*N*2)
*/

#include <bits/stdc++.h> 
#define ll long long int 

int mod = 1e9 + 7;

int evaluateExp(string & exp) {
    int n = exp.size();

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (n+1, vector<int> (2, -1)));
    
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<n; j++) {

            if(i > j) continue;
            for(int isTrue=0; isTrue<=1; isTrue++) {
                

                if(i == j) {
                    if(isTrue == 1) dp[i][j][1]=(exp[i]=='T');
                    else dp[i][j][0]=(exp[i]=='F');
                }

                int ways = 0;
                for(int k=i+1; k<j; k+=2) {
                    ll lT = dp[i][k-1][1];
                    ll lF = dp[i][k-1][0];
                    ll rT = dp[k+1][j][1];
                    ll rF = dp[k+1][j][0];

                    if(exp[k] == '&') {
                        if(isTrue) ways = (ways + (lT*rT) % mod) % mod;
                        else ways = (ways + (lT*rF) % mod + (lF*rT) % mod + (lF*rF) % mod) % mod;
                    } else if(exp[k] == '|') {
                        if(isTrue) ways = (ways + (lT*rF) % mod + (lF*rT) % mod + (lT*rT) % mod) % mod;
                        else ways = (ways + (lF*rF) % mod) % mod;
                    } else if(exp[k] == '^') {
                        if(isTrue) ways = (ways + (lT*rF) % mod + (lF*rT) % mod) % mod;
                        else ways = (ways + (lT*rT) % mod + (lF*rF) % mod) % mod;
                    }

                    dp[i][j][isTrue] = ways;
                }
            
            }
        }
    }

    return dp[0][n-1][1];
}