/*
    Time Complexity - O(n*k)
    Space Complexity - O(n*k)
*/

int findWays(vector<int> &nums, int tar)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int> (tar+1, 0));
    
    for(int idx=0; idx<n; idx++) {
        dp[idx][0] = 1;
    }
    
    if(nums[0]<=tar) {
         dp[0][nums[0]] = 1;    
    }
    
    for(int idx=1; idx<n; idx++) {
        for(int target=1; target<=tar; target++) {
            
            int unpick = dp[idx-1][target];
            int pick = 0;
            if(target-nums[idx]>=0) {
                pick = dp[idx-1][target-nums[idx]];
            }
            
            dp[idx][target] = unpick+pick;
        }
    }
    
    return dp[n-1][tar];
}