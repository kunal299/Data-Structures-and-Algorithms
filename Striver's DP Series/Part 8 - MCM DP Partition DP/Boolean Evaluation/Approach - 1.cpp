/*
    Time Complexity - O((N*N*2)*N)
    Space Complexity - O(N*N*2) + O(N)
*/

#include <bits/stdc++.h> 
#define ll long long int 

int mod = 1e9 + 7;
int helper(int i, int j, int isTrue, string &exp, vector<vector<vector<int>>> &dp) {
    if(i > j) return 0;

    if(i == j) {
        if(isTrue == 1) return exp[i]=='T';
        else return exp[i]=='F';
    }

    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    int ways = 0;
    for(int k=i+1; k<j; k+=2) {
        ll lT = helper(i, k-1, 1, exp, dp);
        ll lF = helper(i, k-1, 0, exp, dp);
        ll rT = helper(k+1, j, 1, exp, dp);
        ll rF = helper(k+1, j, 0, exp, dp);

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
    }

    return dp[i][j][isTrue] = ways;
    
}

int evaluateExp(string & exp) {
    int n = exp.size();

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (n+1, vector<int> (2, -1)));
    return helper(0, n-1, 1, exp, dp);
}