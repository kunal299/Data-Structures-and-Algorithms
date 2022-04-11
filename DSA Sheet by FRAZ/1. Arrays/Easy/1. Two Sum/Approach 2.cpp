/*
    Using Unordered Map
    Time Complexity - O(n)
    Space Complexity - O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for(int i=0; i<nums.size(); i++) {
            int element = target - nums[i];
            if(mp.find(element) != mp.end()) {
                return {i, mp[element]};
            } 

            //Inserting element while searching to avoid the conflict between same numbers with different indexes
            mp[nums[i]] = i;
        }
        
        return {-1, -1};
    }
};