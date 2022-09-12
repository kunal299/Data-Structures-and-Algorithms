/*
    Time Complexity - O(n*k)
    Space Complexity - O(k)
*/

int findWays(vector<int> &nums, int tar)
{
    int n = nums.size();
    vector<int> prev(tar+1, 0);
    
    prev[0] = 1;
    
    if(nums[0]<=tar) {
         prev[nums[0]] = 1;    
    }
    
    for(int idx=1; idx<n; idx++) {
        vector<int> curr(tar+1, 0);
        curr[0] = 1;
        for(int target=1; target<=tar; target++) {
            
            int unpick = prev[target];
            int pick = 0;
            if(target-nums[idx]>=0) {
                pick = prev[target-nums[idx]];
            }
            
            curr[target] = unpick+pick;
        }
        prev = curr;
    }
    
    return prev[tar];
}