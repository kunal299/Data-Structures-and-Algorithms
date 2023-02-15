/*
    Time Complexity - O(n*k)
    Space Complexity - O(n*k) + O(n)
*/

class Solution {
public:
    int helper(int idx, int target, vector<int> &nums, vector<vector<int>> &dp) {
        if(idx==0) {
            if(target==0 && nums[0]==0) {
                return 2;
            } else if(target==0 || target==nums[0]) {
                return 1;
            } else {
                return 0;
            }
        }

        if(dp[idx][target] != -1) return dp[idx][target];

        int notTaken = helper(idx-1, target, nums, dp);
        int taken = 0;
        if(target-nums[idx]>=0) {
            taken = helper(idx-1, target-nums[idx], nums, dp);
        }

        return dp[idx][target]=(notTaken + taken);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int size = nums.size();
        
        int totSum = 0;
        for(int i=0; i<size; i++) {
            totSum += nums[i];
        }

        if(totSum-target<0) return 0;
        if((totSum-target)%2==1) return 0;

        int s2 = (totSum-target)/2;
        vector<vector<int>> dp(size, vector<int> (s2+1, -1));

        int noOfExp = helper(size-1, s2, nums, dp);
        return noOfExp;
    }
};