/* 
    Time Complexity - O(2^n * x)
    Space Complexity - O(k * x)
*/

class Solution {
public:
    void helper(int idx, int target, vector<int>& candidates, vector<vector<int>> &sum, vector<int> res) {
        if(target==0) {
            sum.push_back(res);
            return;
        }
        
        for(int i=idx; i<candidates.size(); i++) {
            if(i!=idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i] > target) break;
            
            res.push_back(candidates[i]);
            helper(i+1, target-candidates[i], candidates, sum, res);
            res.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {  
        vector<vector<int>> sum;
        vector<int> res;
        sort(candidates.begin(), candidates.end());
        
        helper(0, target, candidates, sum, res);
        
        return sum;
    }
};