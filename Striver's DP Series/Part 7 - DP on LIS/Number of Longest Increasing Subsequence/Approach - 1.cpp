/*
    Time Complexity - O(N * N)
    Space Complexity - O(N)
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        
        int maxi = -1;
        for(int i=0; i<n; i++) {
            for(int prev_idx=0; prev_idx<i; prev_idx++) {
                if(nums[i] > nums[prev_idx] && dp[i] < 1 + dp[prev_idx]) {
                    dp[i] = 1 + dp[prev_idx];
                    cnt[i] = cnt[prev_idx];
                } else if(nums[i] > nums[prev_idx] && dp[i] == 1 + dp[prev_idx]) {
                    cnt[i] += cnt[prev_idx];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int no = 0;
        for(int i=0; i<n; i++) {
            if(dp[i] == maxi) {
                no += cnt[i];
            }
        }

        return no;
    }
};