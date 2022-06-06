/*
    Time Complexity - O(N^2)
    Space Complexity - O(N^2)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> dummy(rows, vector<int> (rows,0));
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                dummy[j][rows-i-1] = matrix[i][j];
            }
        }

        matrix = dummy;
    }
};