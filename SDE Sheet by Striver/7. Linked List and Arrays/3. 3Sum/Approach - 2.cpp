/*
    Time Complexity - O(n^2)
    Space Complexity - O(1)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        for(int i=0; i<nums.size(); i++) {
            
            int target = -nums[i];
            
            //Two Pointer Technique
            int low = i+1;
            int high = nums.size() - 1;
            
            while(low < high) {
                int two_sum = nums[low] + nums[high];
                
                if(two_sum == target) {
                    res.push_back({nums[i], nums[low], nums[high]});
                    
                    int store1 = nums[low];
                    int store2 = nums[high];
                    
                    while(low<high && nums[low]==store1) low++;
                    while(low<high && nums[high]==store2) high--;
                } 
                else if(two_sum > target) high--;
                else low++;
            }
            
            while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        }
        
        return res;
    }
};