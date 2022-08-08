/*
    Time Complexity - expo.
    Space Complexity - expo.
*/

class Solution {
public:
    int helper(int s, int e, int m, int n) {
        if(s==m && e==n) {
            return 1;
        }
        
        if(s>m || e>n) {
            return 0;
        }
        
        return helper(s+1, e, m, n) + helper(s, e+1, m, n);
    }
    
    int uniquePaths(int m, int n) {
        return helper(0, 0, m-1, n-1);
    }
};