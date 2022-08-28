/*
    Time Complexity - O(n*m)
    Space Complexity - O(m)
*/

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<int> prev(m, 0);
    
    for(int i=0; i<n; i++) {
        vector<int> tmp(m, 0);
        
        for(int j=0; j<m; j++) {
            
            if(i==0) {
                tmp[j] = matrix[i][j];
            } else {
                
                int d = matrix[i][j] + prev[j];
                int dl = -1e9, dr = -1e9;
                
                if(j+1<m) {
                    dl = matrix[i][j] + prev[j+1];
                }
                
                if(j-1>=0) {
                    dr = matrix[i][j] + prev[j-1];
                }
                
                tmp[j] = max(d, max(dl, dr));
            }
        }
        prev = tmp;
    }
    
    int maxi = -1e9;
    for(int j=0; j<m; j++) {
        maxi = max(maxi, prev[j]);
    }
    
    return maxi;
}