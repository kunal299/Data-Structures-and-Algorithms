/*
    Time Complexity - O(n*k)
    Space Complexity - O(k)
*/

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, 0), curr(k+1, 0);
    prev[0] = curr[0] = true;
    prev[arr[0]] = true;
    
    for(int idx=1; idx<n; idx++) {
        for(int target=1; target<=k; target++) {
            bool unpick = prev[target];
            bool pick = false;
            if(target-arr[idx]>=0) {
                pick = prev[target-arr[idx]];
            }
            
            curr[target] = unpick or pick;
        }
        
        prev = curr;
    }
    
    return prev[k];
}