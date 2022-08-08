/*
    Time Complexity - O(n^2)
    Space Complexity - O(1)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        
        for(int i=0; i<nums.size(); i++) {
            int count = 1;
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[i]==nums[j]) { 
                    count++;
                }
            }
            if(count > floor(nums.size()/3)) {
                v.push_back(nums[i]);
            }
        }

        return v;
    }
};