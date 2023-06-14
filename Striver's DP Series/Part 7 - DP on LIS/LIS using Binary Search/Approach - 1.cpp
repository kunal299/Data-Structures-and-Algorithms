/*
    Time Complexity - O(N * logN)
    Space Complexity - O(N)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> tmp;
        tmp.push_back(nums[0]);
        for(int i=1; i<n; i++) {
            if(nums[i] > tmp.back()) {
                tmp.push_back(nums[i]);
            } else {
                int idx = lower_bound(tmp.begin(), tmp.end(), nums[i])-tmp.begin();
                tmp[idx] = nums[i];
            }
        }

        return tmp.size();
    }
};