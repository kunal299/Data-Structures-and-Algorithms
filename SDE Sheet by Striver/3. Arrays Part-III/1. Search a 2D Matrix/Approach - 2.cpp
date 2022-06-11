/*
    Time Complexity - O(m + n)
    Space Complexity - O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = 0;
        int i;
        for(i=1; i<matrix.size(); i++) {
            if(matrix[i][0]>target) {
                row = i-1;
                break;
            } else if(target>=matrix[i][0]) {
                row = i;
            }
        }
        
        for(i=0; i<matrix[row].size(); i++) {
            if(matrix[row][i]==target) {
                return true;
            }
        }
        
        return false;
    }
};