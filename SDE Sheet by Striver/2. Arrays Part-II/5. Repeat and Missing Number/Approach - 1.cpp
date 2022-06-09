/*
    Time Complexity - O(n)
    Space Complexity - O(n)
*/

//Using Frequency Array

#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    vector<int> v(n+1,0);
    pair<int, int> p;
    
    for(int i=0; i<n; i++) {
        v[arr[i]]++;
    }
    
    for(int i=1; i<=n; i++) {
        if(v[i]==0) {
            p.first = i;
        }
        if(v[i]>1) {
            p.second = i;
        }
    }
    
    return p;
}
