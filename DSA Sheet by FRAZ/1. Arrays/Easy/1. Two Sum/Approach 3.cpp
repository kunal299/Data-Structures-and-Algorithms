/*
    Using Two Pointer Technique
    Time Complexity - O(nlogn)
    Space Complexity - O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> v;
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            v.push_back({nums[i], i});
        }
        
        sort(v.begin(), v.end());
        
        int ptr1 = 0;
        int ptr2 = n-1;
        
        while(ptr1<ptr2) {
            int sum = v[ptr1].first + v[ptr2].first;
            if(sum == target) {
                return {v[ptr1].second, v[ptr2].second};
            } else if(sum > target) {
                ptr2--;
            } else {
                ptr1++;
            }
        }
        
        return {-1, -1};
    }
};