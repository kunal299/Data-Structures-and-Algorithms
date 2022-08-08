/*
    Time Complexity - O(n*m + n*m)
    Space Complexity - O(n)+O(m)

    where n - no. of rows
          m - no. of cols
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<int> v1(rows, -1);
        vector<int> v2(cols, -1);
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(matrix[i][j]==0) {
                    v1[i] = 0;
                    v2[j] = 0;
                }
            }
        }
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(v1[i]==0 || v2[j]==0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};