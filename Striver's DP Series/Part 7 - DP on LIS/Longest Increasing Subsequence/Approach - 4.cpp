/*
    Time Complexity - O(N*N) 
    Space Complexity - O(N)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        //Tabulation Method
        for(int i=0; i<n; i++) {
            for(int prev=0; prev<i; prev++) {

                if(nums[i] > nums[prev]) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }

            }
        }

        int ans = -1;
        for(int i=0; i<n; i++) {
            if(dp[i] > ans) {
                ans = dp[i];
            }
        }

        return ans;
    }
};