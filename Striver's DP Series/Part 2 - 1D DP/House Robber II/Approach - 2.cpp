/*
    Time Complexity - O(n)
    Space Complexity - O(3*n) ~ O(n)
*/

//Tabulation
class Solution {
public:
    int helper(int idx, vector<int> &nums, vector<int> &dp) {
        dp[0] = nums[0];
        
        for(int i=1; i<=idx; i++) {
            int pick = nums[i];
            if(i>=2) {
                 pick += dp[i-2];
            }
            int unpick = 0 + dp[i-1];
            dp[i] = max(pick, unpick);
        }
        
        return dp[idx];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        
        vector<int> dp(nums.size()-1, -1);
        vector<int> arr1, arr2;
        
        for(int i=0; i<nums.size(); i++) {
            if(i!=0) arr1.push_back(nums[i]);
            if(i!=nums.size()-1) arr2.push_back(nums[i]);
        }
        
        int ans1 = helper(arr1.size()-1, arr1, dp);
        fill(dp.begin(), dp.end(), -1);
        int ans2 = helper(arr2.size()-1, arr2, dp);
        
        return max(ans1, ans2);
    }
};