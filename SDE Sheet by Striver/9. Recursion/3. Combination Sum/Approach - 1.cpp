/*
    Time Complexity - O((2^t) * k) 
    Space Complexity - O(k * x)

    where t is the target, k is the average length, x is the no. of combinations
*/

class Solution {
public:
    void helper(int idx, int target, vector<int> &candidates, vector<vector<int>> &sum, vector<int> res) {
        if(idx == candidates.size()) {
            if(target==0) {
                sum.push_back(res);
            }
            return;
        }
    
         if(candidates[idx] <= target) {
            res.push_back(candidates[idx]);
            helper(idx, target-candidates[idx], candidates, sum, res);
            res.pop_back();
        } 
        
        helper(idx+1, target, candidates, sum, res);   
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> res;
        vector<vector<int>> sum;
        helper(0, target, candidates, sum, res);
        
        return sum;
    }
};