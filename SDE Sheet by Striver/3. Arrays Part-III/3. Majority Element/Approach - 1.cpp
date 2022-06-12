/*
    Time Complexity - O(n^2)
    Space Complexity - O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count;
        for(int i=0; i<nums.size(); i++) {
            count = 1;
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[i]==nums[j]) {
                    count++;
                }
                if(count>floor(nums.size()/2)) {
                    return nums[i];
                }
            }
        }

        return -1;
    }
};