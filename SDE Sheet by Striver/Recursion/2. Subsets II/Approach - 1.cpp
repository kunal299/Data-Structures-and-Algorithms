/*
    Time Complexity - O((2^n) * (klogx)) * (2^n)
    Space Complexity - O((2^n) * k)
*/

class Solution {
public:
    void helper(int idx, vector<int> &nums, int n, set<vector<int>> &st, vector<int> res) {
        if(idx == n) {
            sort(res.begin(), res.end());
            st.insert(res);
            return;
        }
        
        res.push_back(nums[idx]);
        helper(idx+1, nums, n, st, res);
        res.pop_back();
        helper(idx+1, nums, n, st, res);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> res;
        set<vector<int>> st;
        helper(0, nums, nums.size(), st, res);
        
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};