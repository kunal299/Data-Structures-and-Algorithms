/*
    Time Complexity - o(n^3)
    Space Complexity - O(1)
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        for(int i=0; i<n; i++) {
            int target_3 = target - nums[i];
            for(int j=i+1; j<n; j++) {
                
                long long target_2 = (long long)target_3 - (long long)nums[j];
                
                int low = j+1; 
                int high = n-1;
                
                while(low < high) {
                    int two_sum = nums[low] + nums[high];
                    
                    if(two_sum == target_2) {
                        res.push_back({nums[i], nums[j], nums[low], nums[high]});
                        
                        int store1 = nums[low];
                        int store2 = nums[high];
                        
                        while(low < high && nums[low]==store1) {
                            low++;
                        }
                        
                        while(low < high && nums[high]==store2) {
                            high--;
                        }
                        
                    } else if(two_sum > target_2) {
                        high--;
                    } else {
                        low++;
                    }
                }
                
                while(j+1 < n && nums[j]==nums[j+1]) {
                    j++;
                } 
            }
            
            while(i+1 < n && nums[i]==nums[i+1]) {
                i++;
            } 
        }
        
        return res;
    }
};