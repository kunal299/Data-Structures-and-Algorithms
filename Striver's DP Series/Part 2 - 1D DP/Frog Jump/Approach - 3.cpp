/*
    Time Complexity - O(n)
    Space Complexity - O(1)
*/

int frogJump(int n, vector<int> &heights)
{
    int prev = 0;
    int prev2 = 0;
    
    for(int i=1; i<n; i++) {
        int jump1 = prev + abs(heights[i]-heights[i-1]);
        int jump2 = INT_MAX;
        if(i>1) {
            jump2 = prev2 + abs(heights[i]-heights[i-2]);
        }
        
        int curr = min(jump1, jump2);
        prev2 = prev;
        prev = curr;
    }
    
    return prev;
}