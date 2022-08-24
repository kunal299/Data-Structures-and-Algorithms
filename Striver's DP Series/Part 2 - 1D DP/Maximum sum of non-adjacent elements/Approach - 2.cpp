/*
    Time Complexity - O(n)
    Space Complexity - O(n)
*/

//Tabulation
int helper(vector<int> &nums, vector<int> &dp, int idx) {
    if(idx<0) return 0;
    
    dp[0] = nums[0];
    for(int i=1; i<=idx; i++) {
        int picked = -1;
        if(idx>=1) {
            picked = nums[i] + dp[i-2];
        }
        int unpicked = dp[i-1];
        dp[i] = max(picked, unpicked);
    }
    
    return dp[idx];
}

int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size(), -1);
    return helper(nums, dp, nums.size()-1);
}