/*
    Time Complexity - O(n)
    Space Complexity - O(1)
*/

class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    void reverse(vector<int>& nums, int si, int ei) {
        while(si < ei) {
            swap(nums, si, ei);
            si++;
            ei--;
        }
    }
     
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
            
        int idx1 = -1;
        for(int i=size-1; i>0; i--) {
            if(nums[i]>nums[i-1]) {
                idx1 = i-1;
                break;
            }
        }
        
        if(idx1==-1) {
            reverse(nums, 0, size-1);
            return;
        }
        
        for(int i=size-1; i>idx1; i--) {
            if(nums[idx1]<nums[i]) {
                swap(nums, idx1, i);
                break;
            }
        }
        
        reverse(nums, idx1+1, size-1);
    }
};