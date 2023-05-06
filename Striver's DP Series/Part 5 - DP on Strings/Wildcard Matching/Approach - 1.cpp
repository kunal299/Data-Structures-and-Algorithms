/*
    Time Complexity - O(M*N)
    Space Complexity - O(M*N) + O(M+N)
*/

class Solution {
public:
    bool isAllStars(string &p, int j) {
        for(int i=0; i<=j; i++) {
            if(p[i] != '*') return false;
        }
        
        return true;
    }
    
    bool helper(string &s, string &p, int i, int j, vector<vector<int>> &dp) {
        //If s is exhausted but p is not
        if(i<0 && j>=0) return isAllStars(p, j);
        
        //If s is exhausted and p is also exhausted
        if(i<0 && j<0) return true;
        
        //If s is not exhausted but p is exhausted
        if(i>=0 && j<0) return false;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = helper(s, p, i-1, j-1, dp);
        } else {
            if(p[j] == '*') {
                return dp[i][j] = (helper(s, p, i, j-1, dp)  || helper(s, p, i-1, j, dp));
            } else {
                return false;
            }
        }
    }
    
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(s, p, m-1, n-1, dp);
    }
};