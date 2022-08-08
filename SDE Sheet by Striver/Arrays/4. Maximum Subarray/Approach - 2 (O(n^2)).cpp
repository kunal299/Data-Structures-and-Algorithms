/*
    Time Complexity - O(N^2)
    Space Complexity - O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        
        int maxi = INT_MIN;
        for(int i=0; i<size; i++) {
            int sum = 0;
            for(int j=i; j<size; j++) {
                sum += nums[j];
                maxi = max(maxi, sum);
            }
        }
        
        return maxi;
    }
};