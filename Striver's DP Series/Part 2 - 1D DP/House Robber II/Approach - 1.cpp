/*
    Time Complexity - O(n)
    Space Complexity - O(3*n) ~ O(n)
*/

//Memoization
class Solution {
public:
    int helper(int idx, vector<int> &nums, vector<int> &dp) {
        if(idx==0) return nums[0];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        
        int pick = nums[idx] + helper(idx-2, nums, dp);
        int unpick = 0 + helper(idx-1, nums, dp);
        
        return dp[idx]=max(pick, unpick);
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