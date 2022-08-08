/*
    Time Complexity - O(n^3)
    Space Complexity - O(1)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> res;
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    if(nums[i]+nums[j]+nums[k]==0) {
                        res.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        
        return res;
    }
};