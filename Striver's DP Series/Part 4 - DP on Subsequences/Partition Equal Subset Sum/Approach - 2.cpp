/*
    Time Complexity - O(n*k) + O(n)
    Space Complexity - O(n*k)

    where k is the target
*/

class Solution {
public: 
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }
        
        if(sum%2!=0) {
            return false;
        }
        
        vector<vector<bool>> dp(n, vector<bool> ((sum/2)+1, false));
        for(int idx=0; idx<n; idx++) {
            dp[idx][0] = true;
        }
        
        if(nums[0] <= sum/2) {
            dp[0][nums[0]] = true;   
        }
        
        for(int idx=1; idx<n; idx++) {
            for(int target=1; target<=sum/2; target++) {
                
                int unpick = dp[idx-1][target];
                int pick = false;
                if(target-nums[idx]>=0) {
                    pick = dp[idx-1][target-nums[idx]];
                }
        
                dp[idx][target] = pick or unpick;
            }
        }
        
        return dp[n-1][sum/2];
    }
};