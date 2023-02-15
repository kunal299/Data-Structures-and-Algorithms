/*
    Time Complexity - O(n*k)
    Space Complexity - O(k)
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int size = nums.size();
        
        int totSum = 0;
        for(int i=0; i<size; i++) {
            totSum += nums[i];
        }

        if(totSum-target<0) return 0;
        if((totSum-target)%2==1) return 0;

        int s2 = (totSum-target)/2;
        vector<int> prev(s2+1, 0), curr(s2+1, 0);

        if(nums[0]==0) {
            prev[0] = 2;
        } else {
            prev[0] = 1;
        }

        if(nums[0]!=0 && nums[0]<=s2) prev[nums[0]] = 1;

        for(int idx=1; idx<size; idx++) {
            for(int tar=0; tar<=s2; tar++) {
                int notTaken = prev[tar];
                
                int taken = 0;
                if(tar-nums[idx]>=0) {
                    taken = prev[tar-nums[idx]];
                }

                curr[tar] = notTaken + taken;
            }
            prev = curr;
        }
        
        return prev[s2];
    }
};