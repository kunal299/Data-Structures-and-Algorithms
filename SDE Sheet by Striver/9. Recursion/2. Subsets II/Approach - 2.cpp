/*
    Time Complexity - O(2^n * k) 
    Space Complexity - O(2^n * k) 
    Auxiliary Space - O(n)
*/

class Solution {
public:
    void helper(int idx, vector<int> &nums, int n, vector<vector<int>> &vv, vector<int> &res) {
        vv.push_back(res);
        for(int i=idx; i<nums.size(); i++) {
            if(i!=idx && nums[i]==nums[i-1]) continue;
    
            res.push_back(nums[i]);
            helper(i+1, nums, n, vv, res);
            res.pop_back();  
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> res;
        vector<vector<int>> vv;
        sort(nums.begin(), nums.end());
        helper(0, nums, nums.size(), vv, res);
        
        return vv;
    }
};