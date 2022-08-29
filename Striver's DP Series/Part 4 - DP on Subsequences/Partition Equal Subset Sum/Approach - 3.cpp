/*
    Time Complexity - O(n*k) + O(n)
    Space Complexity - O(k)

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
        
        vector<bool> prev((sum/2)+1, false), curr((sum/2)+1, false);
        prev[0] = curr[0] = true;
        
        if(nums[0] <= sum/2) {
            prev[nums[0]] = true;   
        }
        
        for(int idx=1; idx<n; idx++) {
            for(int target=1; target<=sum/2; target++) {
                
                int unpick = prev[target];
                int pick = false;
                if(target-nums[idx]>=0) {
                    pick = prev[target-nums[idx]];
                }
        
                curr[target] = pick or unpick;
            }
            prev = curr;
        }
        
        return prev[sum/2];
    }
};