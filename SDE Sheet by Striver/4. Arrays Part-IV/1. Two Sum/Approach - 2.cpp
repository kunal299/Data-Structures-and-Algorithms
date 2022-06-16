/*
    Time Complexity - O(nlogn)
    Space Complexity - O(n)
*/

//Using Two Pointer Approach 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        
        vector<pair<int, int>> v1;
        for(int i=0; i<nums.size(); i++) {
            v1.push_back({nums[i], i});
        }
        
        sort(v1.begin(), v1.end());
        
        int low = 0;
        int high = nums.size()-1;
        
        while(low < high) {
            if((v1[low].first + v1[high].first) == target) {
                v.push_back(v1[low].second);
                v.push_back(v1[high].second);
                break;
            } else if((v1[low].first + v1[high].first) > target) {
                high--;
            } else {
                low++;
            }
        }
        
        return v;
    }
};