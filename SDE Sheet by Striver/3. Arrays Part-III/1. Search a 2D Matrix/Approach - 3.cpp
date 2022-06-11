/*
    Time Complexity - O(log(m*n))
    Space Complexity - O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0; 
        int hi = (matrix.size()*matrix[0].size()) - 1;

        while(lo <= hi) {
            int mid = (lo+hi)/2;
            int i = mid / matrix[0].size();
            int j = mid % matrix[0].size(); 
            
            if(matrix[i][j]==target) {
                return true;
            } else if(matrix[i][j] > target) {
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        
        return false;
    }
};