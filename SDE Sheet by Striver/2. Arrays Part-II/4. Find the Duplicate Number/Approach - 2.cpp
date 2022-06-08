/*
    Time Complexity - O(n)
    Space Complexity - O(n)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        vector<int> v(nums.size()+1, 0);
        for(int i=0; i<nums.size(); i++) {
            v[nums[i]]++;
            if(v[nums[i]]>1) {
                return nums[i];
            }
        }
        return -1;
    }
};