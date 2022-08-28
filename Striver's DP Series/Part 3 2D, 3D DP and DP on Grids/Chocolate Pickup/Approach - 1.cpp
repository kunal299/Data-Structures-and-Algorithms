/*
    Time Complexity - O(n*m*m) * 9
    Space Complexity - O(n*m*m) + O(n)

    where n - no. of rows
          m - no. of cols
*/

//Using Memoization
int helper(int i, int j1, int j2, int r, int c, vector<vector < int>> &grid, vector< vector< vector< int>>> &dp) {
    if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) return -1e8;

    if (i == r - 1) {
        if (j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++) {
        for (int dj2 = -1; dj2 <= 1; dj2++) {
            int value = 0;
            if (j1 == j2) value = grid[i][j1];
            else value = grid[i][j1] + grid[i][j2];

            maxi = max(maxi, value + helper(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp));
        }
    }

    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c, -1)));
    return helper(0, 0, c-1, r, c, grid, dp);
}