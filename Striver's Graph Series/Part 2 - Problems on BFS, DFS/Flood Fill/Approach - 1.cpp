/*
    Time Complexity - O(m*n) + O(m*n*4) ~ O(m*n)
    Space Complexity - O(m*n) + O(m*n) ~ O(m*n)
*/

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int iniColor, int drow[], int dcol[]) {
        ans[row][col] = newColor;

        int m = image.size();
        int n = image[0].size();

        for(int i=0; i<4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && nrow<=m-1 && ncol>=0 && ncol<=n-1 && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, ans, image, newColor, iniColor, drow, dcol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int iniColor = image[sr][sc];

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        vector<vector<int>> ans = image;

        dfs(sr, sc, ans, image, color, iniColor, drow, dcol);
        return ans;
    }
};