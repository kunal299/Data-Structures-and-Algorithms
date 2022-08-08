/*
    Time Complexity - O(n! * n)
    Space Complexity - O(n)
*/

class Solution {
public:
    void helper(map<int, bool> &mp, vector<int>& nums, vector<int> &ds, vector<vector<int>> &ans) {
        if(ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        
        for(int i=0; i<nums.size(); i++) {
            if(mp[i] == true) {
                ds.push_back(nums[i]);
                mp[i] = false;
                helper(mp, nums, ds, ans);
                mp[i] = true;
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        map<int, bool> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[i] = true;
        }
        
        vector<int> ds;
        vector<vector<int>> ans;
        
        helper(mp, nums, ds, ans);
        
        return ans;
    }
};