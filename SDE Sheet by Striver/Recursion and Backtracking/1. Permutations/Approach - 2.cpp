/*
    Time Complexity - O(n! * n)
    Space Complexity - O(1)
*/

class Solution {
public:
    void helper(int idx, vector<vector<int>> &ans, vector<int> &nums) {
        if(idx == nums.size()) {
            vector<int> ds;
            for(int i=0; i<nums.size(); i++) {
                ds.push_back(nums[i]);
            }
            ans.push_back(ds);
            return;
        }
        
        for(int i=idx; i<nums.size(); i++) {
            swap(nums[i], nums[idx]);
            helper(idx+1, ans, nums);
            swap(nums[i], nums[idx]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0, ans, nums);
        
        return ans;
    }
};