/*
    Time Complexity - O(N^2)
    Space Complexity - O(1)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int i=0; i<rows; i++) {
            for(int j=i+1; j<cols; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
            for(int k=0; k<cols/2; k++) {
                swap(matrix[i][k], matrix[i][cols-k-1]);
            }
        }
        
    }
};