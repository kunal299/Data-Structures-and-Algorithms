/*
    Time Complexity - O(n^2)
    Space Complexity - O(1)
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            int j = i;
            int leftMax = 0, rightMax = 0;
            
            while (j >= 0) {
                leftMax = max(leftMax, height[j]);
                j--;
            }

            j = i;
            while (j < n) {
                rightMax = max(rightMax, height[j]);
                j++;
            }
            
            res += min(leftMax, rightMax) - height[i];
        }
        
        return res;
    }
};