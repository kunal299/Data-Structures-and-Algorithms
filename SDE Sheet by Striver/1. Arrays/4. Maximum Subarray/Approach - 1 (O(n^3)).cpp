/*
    Time Complexity - O(N^3)
    Space Complexity - O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if(size==1) {
            return nums[0];
        }
        
        int maxi = INT_MIN;
        for(int i=0; i<size; i++) {
            for(int j=i; j<size; j++) {
                int sum = 0;
                for(int k=i; k<=j; k++) {
                    sum += nums[k];
                }
                maxi = max(maxi, sum);
            }
        }
        
        return maxi;
    }
};