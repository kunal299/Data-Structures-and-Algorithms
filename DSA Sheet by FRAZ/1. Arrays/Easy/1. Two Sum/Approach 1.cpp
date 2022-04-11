/*
    Using 2 For Loops
    Time Complexity - O(n^2)
    Space Complexity - O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size()-1; i++) {
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[i]+nums[j]==target) {
                    return {i, j};
                }
            }
        }
        
        return {-1, -1};
    }
};