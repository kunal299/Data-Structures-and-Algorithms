/*
    Time Complexity - O(n*4*3) ~ O(n)
    Space Complexity - O(n) + O(n*4) ~ O(n) 

*/

//Memoization
int helper(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if(dp[day][last] != -1) return dp[day][last];
    
    if(day==0) {
        int maxi = 0;
        for(int i=0; i<=2; i++) {
            if(i!=last) {
                maxi = max(maxi, points[day][i]);
            }
        }
        return dp[day][last] = maxi;
    }
    
    int maxi = 0;
    for(int i=0; i<=2; i++) {
        if(i!=last) {
            maxi = max(maxi, points[day][i] + helper(day-1 , i, points, dp));
        }
    }
    
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int> (4, -1));
    return helper(n-1, 3, points, dp);
}