/*
    Time Complexity - O(M*N*4)
    Space Complexity - O(M*N) + O(M*N)
*/

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));
        queue<pair<int, int>> q;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 || i==m-1 || j==0 || j==n-1) {
                    if(grid[i][j] == 1) {
                        vis[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
        }

        int trow[] = {-1, 0, 1, 0};
        int tcol[] = {0, -1, 0, 1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int i=0; i<4; i++) {
                int nrow = row + trow[i];
                int ncol = col + tcol[i];

                if(nrow>=0 && nrow<=m-1 && ncol>=0 && ncol<=n-1 && vis[nrow][ncol]==0 && grid[nrow][ncol]==1) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                } 
            }
        }

        int landCells = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(vis[i][j] == 0 && grid[i][j] == 1) {
                    landCells++;
                }
            }
        }

        return landCells;
    }
};