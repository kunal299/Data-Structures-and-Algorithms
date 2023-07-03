/*
	Time Complexity - O(m*n + m*n*4) 
	Space Complexity - O(m*n) + O(m*n) + O(m*n)  (vis, dis, queue)
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
		int n = mat[0].size();

		vector<vector<int>> vis(m, vector<int> (n, 0));
		vector<vector<int>> dist(m, vector<int> (n, 0));

		queue<pair<pair<int, int>, int>> q;

		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(mat[i][j] == 0) {
					q.push({{i, j}, 0});
					vis[i][j] = 1;
				} 
			}
		}

		int trow[] = {-1, 0, 1, 0};
		int tcol[] = {0, -1, 0, 1};

		while(!q.empty()) {
			int r = q.front().first.first;
			int c = q.front().first.second;
			int d = q.front().second;

			q.pop();

			dist[r][c] = d;

			for(int i=0; i<4; i++) {
				int nrow = r + trow[i];
				int ncol = c + tcol[i];

				if(nrow>=0 && nrow<=m-1 && ncol>=0 && ncol<=n-1 && vis[nrow][ncol] == 0) {
					vis[nrow][ncol] = 1;
					q.push({{nrow, ncol}, d + 1});
				}
			}
		}

		return dist;
    }
};