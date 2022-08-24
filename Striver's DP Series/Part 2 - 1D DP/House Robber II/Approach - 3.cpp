/*
    Time Complexity - O(n)
    Space Complexity - O(2*n) ~ O(n)
*/

//Removing the dp array 
class Solution {
public:
    int helper(int idx, vector<int> &nums) {
        int prev = nums[0], prev2 = 0;
        
        for(int i=1; i<=idx; i++) {
            int pick = nums[i];
            if(i>=2) {
                 pick += prev2;
            }
            int unpick = 0 + prev;
            int curr = max(pick, unpick);
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        
        vector<int> arr1, arr2;
        
        for(int i=0; i<nums.size(); i++) {
            if(i!=0) arr1.push_back(nums[i]);
            if(i!=nums.size()-1) arr2.push_back(nums[i]);
        }
        
        int ans1 = helper(arr1.size()-1, arr1);
        int ans2 = helper(arr2.size()-1, arr2);
        
        return max(ans1, ans2);
    }
};