/*
    Time Complexity - O(nlogn)
    Space Complexity - O(n)
*/

class Solution {
public:    
        
    int merge(vector<int> &nums, vector<int> &tmp, int left, int mid, int right) {
        int i=left, j=mid, k=left;
        int cnt_rev = 0;
    
        for(i=left; i<mid; i++) {
            while((j<=right) && (nums[i] > (long long)((long long)2 * nums[j]))) {
                j++;
            }
            cnt_rev += (j-mid);
        }
    
        i = left;
        j = mid;
    
        while((i<mid) && (j<=right)) {
            if(nums[i] > nums[j]) {
                tmp[k++] = nums[j++];
            } else {
                tmp[k++] = nums[i++];
            }
        }
    
        while(i<mid) {
            tmp[k++] = nums[i++];
        }
    
        while(j<=right) {
            tmp[k++] = nums[j++];
        }
    
        for(i=left; i<=right; i++) {
            nums[i] = tmp[i];
        }
    
        return cnt_rev;
    }

    int mergeSort(vector<int> &nums, vector<int> &tmp, int left, int right) {
        int cnt_rev = 0;
        if(right > left) {
            int mid = (left+right)/2;
            cnt_rev += mergeSort(nums, tmp, left, mid);
            cnt_rev += mergeSort(nums, tmp, mid+1, right);
        
            cnt_rev += merge(nums, tmp, left, mid+1, right);
        }
    
        return cnt_rev;
    }
            
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n, 0);
        return mergeSort(nums, tmp, 0, n-1);
    }
};