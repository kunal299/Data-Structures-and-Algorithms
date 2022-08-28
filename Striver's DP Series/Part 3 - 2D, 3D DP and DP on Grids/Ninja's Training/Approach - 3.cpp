/*
    Time Complexity - O(n*4*3) ~ O(n)
    Space Complexity - O(4) ~ O(1)
*/

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);
    
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
    
    for(int day=1; day<n; day++) {
        vector<int> tmp(4, 0);
        for(int last=0; last<4; last++) {
            int maxi = 0;
            for(int task=0; task<=2; task++) {
                if(last!=task) {
                    maxi = max(maxi, points[day][task] + prev[task]);
                    tmp[last] = maxi;
                }
            }
        }
        prev = tmp;
    }
    
    return prev[3];
}