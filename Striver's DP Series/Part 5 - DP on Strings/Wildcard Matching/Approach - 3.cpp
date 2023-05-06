/*
    Time Complexity - O(M*N)
    Space Complexity - O(N)
*/

class Solution {
public:
    bool isAllStars(string &p, int j) {
        for(int i=0; i<=j; i++) {
            if(p[i] != '*') return false;
        }
        
        return true;
    }
    
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        vector<bool> prev(n+1, false), curr(n+1, false);
        
        prev[0] = true;
        for(int j=1; j<=n; j++) {
            prev[j] = isAllStars(p, j-1);
        }

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {

                if(s[i-1] == p[j-1] || p[j-1] == '?') {
                    curr[j] = prev[j-1];
                } else {
                    if(p[j-1] == '*') {
                        curr[j] = (curr[j-1]  || prev[j]);
                    } else {
                        curr[j] = false;
                    }
                }

            }
            prev = curr;
        }

        return prev[n];
    }
};