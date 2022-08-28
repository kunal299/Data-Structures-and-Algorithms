/*
    Time Complexity - O(n*4*3) ~ O(n)
    Space Complexity - O(n*4) ~ O(n)
*/

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int> (4, -1));
    
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    
    for(int day=1; day<n; day++) {
        for(int last=0; last<=3; last++) {
            int maxi = 0;
            for(int task=0; task<=2; task++) {
                if(task!=last) {
                    maxi = max(maxi, points[day][task] + dp[day-1][task]);
                    dp[day][last] = maxi;
                }
            }
        }
    }
   
    return dp[n-1][3];
}