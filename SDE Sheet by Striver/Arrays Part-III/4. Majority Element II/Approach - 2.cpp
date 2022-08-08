/*
    Time Complexity - O(n)
    Space Complexity - O(n)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> v;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
            
        for(auto &it: mp) {
            if(it.second > floor(nums.size()/3)) {
                v.push_back(it.first);
            }
        }
        
        return v;
    }
};