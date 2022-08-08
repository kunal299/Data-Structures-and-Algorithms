/*
    Time Complexity - O(N)
    Space Complexity - O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        
        int sum = 0;
        int maxi = INT_MIN;
        
        for(int i=0; i<size; i++) {
            sum += nums[i];
            maxi = max(maxi, sum);
            if(sum<0) {
                sum = 0;
            }
        }
        
        return maxi;
    }
};