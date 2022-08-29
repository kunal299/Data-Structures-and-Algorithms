/*
    Time Complexity - O(n) + O(n*k)
    Space Complexity - O(n) + O(n*k) 

    where k is the target
*/

class Solution {
public:
    bool helper(int idx, int target, vector<int> &nums, vector<vector<int>> &dp) {
        if(target == 0) return true;
        if(idx == 0) return nums[idx]==target;
        if(dp[idx][target] != -1) return dp[idx][target]; 
        
        int unpick = helper(idx-1, target, nums, dp);
        int pick = false;
        if(target-nums[idx]>=0) {
            pick = helper(idx-1, target-nums[idx], nums, dp);
        }
        
        return dp[idx][target] = pick or unpick;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }
        
        if(sum%2!=0) {
            return false;
        }
        
        vector<vector<int>> dp(n, vector<int> ((sum/2)+1, -1));
        return helper(n-1, sum/2, nums, dp);
    }
};