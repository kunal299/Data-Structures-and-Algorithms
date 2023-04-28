/*
    Time Complexity - O(M*N)
    Space Complexity - O(N)
*/

#include <bits/stdc++.h> 

int lcs(string str, string ptr) {
    int m = str.length();
    int n = ptr.length();

    vector<int> curr(n+1, 0), prev(n+1, 0);
    
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {

            if(str[i-1] == ptr[j-1]) {
                curr[j] = 1 + prev[j-1];
            } else {
                curr[j] = max(prev[j], curr[j-1]);
            }

        }
        prev = curr;
    }

    return curr[n];
}

int canYouMake(string &str, string &ptr)
{
    int t = lcs(str, ptr);
    int m = str.length();
    int n = ptr.length();

    return (m-t) + (n-t);
}