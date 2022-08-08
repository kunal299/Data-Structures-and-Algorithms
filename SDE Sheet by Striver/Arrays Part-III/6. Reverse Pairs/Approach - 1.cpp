/*
    Time Complexity - O(n^2)
    Space Complexity - O(1)
*/

class Solution {
public:    
    int reversePairs(vector<int>& nums) {
        int cnt_rev = 0;
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[i] > 2*nums[j]) {
                    cnt_rev++;
                }
            }
        }

        return cnt_rev;
    }
};