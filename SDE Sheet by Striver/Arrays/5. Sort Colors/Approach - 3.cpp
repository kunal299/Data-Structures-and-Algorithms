/*
    Time Complexity - O(n) (It sorts in one pass only)
    Space Complexity - O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        
        int lptr = 0;
        int mptr = 0;
        int hptr = size-1;
        
        while(mptr<=hptr) {
            switch(nums[mptr]) {
                
                //If the element is 0
                case 0: 
                    swap(nums[lptr++], nums[mptr++]);
                    break;
                
                //If the element is 1
                case 1: 
                    mptr++;
                    break;
                 
                //If the element is 2
                case 2:
                    swap(nums[mptr], nums[hptr--]);
                    break;
            }
        }
    }
};