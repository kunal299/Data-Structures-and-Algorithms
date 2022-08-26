/*
    Time Complexity - O(m*n)
    Space Complexity - O(n)
*/

class Solution {
public:
    int helper(int m, int n) {
        
        vector<int> prev(n, 0);
        for(int i=0; i<m; i++) {
            vector<int> tmp(n, 0);
            
            for(int j=0; j<n; j++) {
                
                //Base Case
                if(i==0 && j==0) {
                    tmp[j] = 1;
                    continue;
                }
                
                int up=0, left=0;
                if(i>0) {
                    up = prev[j];
                }
                
                if(j>0) {
                    left = tmp[j-1];
                }
                
                tmp[j] = up+left; 
            }
            
            prev = tmp;
        }
        
        return prev[n-1];
    }
    
    int uniquePaths(int m, int n) {
        return helper(m, n);
    }
};