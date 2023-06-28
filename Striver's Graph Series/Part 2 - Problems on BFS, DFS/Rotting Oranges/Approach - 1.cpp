/*
    Time Complexity - O(m*n) + O(m*n*4) ~ O(m*n)
    Space Complexity - O(m*n) + O(m*n) ~ O(m*n)
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int vis[m][n];
        queue<pair<pair<int, int>, int>> q;

        int cntFresh = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }

                if(grid[i][j] == 1) cntFresh++;
            }
        }

        int tm = 0;
        int cnt = 0;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, -1, 0, +1};
        
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);

            q.pop();

            for(int i=0; i<4; i++) {

                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr>=0 && nr<=m-1 && nc>=0 && nc<=n-1 && vis[nr][nc] == 0 && grid[nr][nc] == 1) {
                    q.push({{nr, nc}, t+1});
                    vis[nr][nc] = 2;
                    cnt++;
                }
            }
        }

        if(cnt != cntFresh) return -1;

        return tm;
    }
};