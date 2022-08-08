/*
    Time Complexity - O(n) (but less efficient as it requires more than one pass) 
    Space Complexity - O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) cnt0++;
            else if(nums[i]==1) cnt1++;
            else cnt2++;
        }
        
        for(int i=0; i<cnt0; i++) {
            nums[i] = 0;
        }
        
        cnt1 += cnt0;
        for(int i=cnt0; i<cnt1; i++) {
            nums[i] = 1;
        }
        
        cnt2 += cnt1;
        for(int i=cnt1; i<cnt2; i++) {
            nums[i] = 2;
        }
    }
};