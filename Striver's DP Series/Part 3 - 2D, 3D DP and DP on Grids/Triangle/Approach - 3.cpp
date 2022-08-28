/*
    Time Complexity - O(m*m)
    Space Complexity - O(m)
*/

class Solution {
public:    
    int minimumTotal(vector<vector<int>>& triangle) {   
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int> (m, 0));
        
        vector<int> next(m, 0);
        for(int j=0; j<m; j++) {
            next[j] = triangle[m-1][j];
        }
        
        for(int i=m-2; i>=0; i--) {
            vector<int> tmp(m, 0);
            
            for(int j=i; j>=0; j--) {
                tmp[j] = min(triangle[i][j] + next[j], triangle[i][j] + next[j+1]);
            }
            
            next = tmp;
        }
        
        return next[0];
    }
};