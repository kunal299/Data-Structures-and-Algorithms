/*
    Time Complexity - O(n)
    Space Complexity - O(1)
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int storeMax = 0;
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==1) {
                count++;
                storeMax = max(storeMax, count);
            } else {
                count = 0;
            }
        }
        
        return storeMax;
    }
};