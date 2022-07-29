/*
    Time Complexity - O(n * n!) + O(n! * log(n!))
    Space Complexity - O(n)
*/

class Solution {
public:
    void helper(string &s, int idx, vector<string> &ans) {
        if(idx==s.size()) {
            ans.push_back(s);
            return;
        }
        
        for(int i=idx; i<s.size(); i++) {
            swap(s[idx], s[i]);
            helper(s, idx+1, ans);
            swap(s[idx], s[i]);
        }
    }
    
    string getPermutation(int n, int k) {
        vector<string> ans;
        string s = "";
        for(int i=1; i<=n; i++) {
            s += (i+'0');
        }
        
        helper(s, 0, ans);
        sort(ans.begin(), ans.end());
        
        return ans[k-1];
    }
};