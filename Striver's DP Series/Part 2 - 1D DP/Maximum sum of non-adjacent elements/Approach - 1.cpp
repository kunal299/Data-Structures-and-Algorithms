/*
    Time Complexity - O(n)
    Space Complexity - O(n)
*/

//Memoization
int helper(vector<int> &nums, vector<int> &dp, int idx) {
    if(idx==0) return nums[idx];
    if(idx<0) return 0;
    if(dp[idx]!=-1) return dp[idx];
    
    int picked = nums[idx] + helper(nums, dp, idx-2);
    int unpicked = 0 + helper(nums, dp, idx-1);
    
    return dp[idx]=max(picked, unpicked);
}

int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size(), -1);
    return helper(nums, dp, nums.size()-1);
}