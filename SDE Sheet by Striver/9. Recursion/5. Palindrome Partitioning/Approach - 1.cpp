/*
    Time Complexity - O((2^n) * k * (n/2))
    Space Complexity - O(k * x)
*/

class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
    
    void helper(int idx, string s, vector<vector<string>> &ans, vector<string> &res) {
        if(idx == s.size()) {
            ans.push_back(res);
            return;
        }
        
        for(int i=idx; i<s.size(); i++) {
            if(isPalindrome(s, idx, i)) {
                res.push_back(s.substr(idx, i-idx+1));
                helper(i+1, s, ans, res);
                res.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;
        
        helper(0, s, ans, res);
        return ans;
    }
};