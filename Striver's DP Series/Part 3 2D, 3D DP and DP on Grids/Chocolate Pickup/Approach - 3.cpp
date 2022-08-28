/*
    Time Complexity - O(n*m*m) * 9 
    Space Complexity - O(m*m)

    where n - no. of rows
          m - no. of cols
*/

//Space Optimization
/*
    1-D -> Two variables
    2-D -> 1D dp
    3-D -> 2D dp
*/
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<int>> next(c, vector<int> (c, 0));
    vector<vector<int>> curr(c, vector<int> (c, 0));
    
    for(int j1=0; j1<c; j1++) {
        for(int j2=0; j2<c; j2++) {
            if(j1==j2) next[j1][j2] = grid[r-1][j1];
            else next[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }
    
    for(int i=r-2; i>=0; i--) {
        for(int j1=c-1; j1>=0; j1--) {
            for(int j2=c-1; j2>=0; j2--) {
                
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++) {
                    for (int dj2 = -1; dj2 <= 1; dj2++) {
                        int value = 0;
                        if (j1 == j2) value = grid[i][j1];
                        else value = grid[i][j1] + grid[i][j2];
                        
                        if(j1+dj1>=0 && j1+dj1<c && j2+dj2>=0 && j2+dj2<c) {
                            value += next[j1+dj1][j2+dj2];
                        } else {
                            value -= 1e8;
                        }
                        
                        maxi = max(maxi, value);
                    }
                }
                
                curr[j1][j2] = maxi;
            }
        }
        next = curr;
    }
                                   
    return next[0][c-1];
}