/*
    Time Complexity - O(n*k)
    Space Complexity - O(k)
*/

#include <bits/stdc++.h> 

int mod =(int)1e9+7;

int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = 0;
    for(int i=0; i<n; i++) {
        totSum += arr[i];
    }
    
    if((totSum-d)<0 || (totSum-d)%2==1) {
        return 0;
    }
    
    int tmp = (totSum - d)/2;
    vector<int> prev(tmp+1, 0);
    
    if(arr[0]==0) prev[0] = 2;
    else prev[0] = 1;
    
    if(arr[0]!=0 && arr[0]<=tmp) prev[arr[0]] = 1;
    
    for(int idx=1; idx<n; idx++) {
        vector<int> curr(tmp+1, 0);
        
        for(int tar=0; tar<=tmp; tar++) {
            
            int notPick = prev[tar];
            int pick = 0;
            if(tar-arr[idx]>=0) {
                pick = prev[tar-arr[idx]];
            }
            
            curr[tar] = (notPick+pick)%mod;
        }
        prev = curr;
    }
    
    return prev[tmp]; 
}


