/*
    Time Complexity - O(nlogn)
    Space Complexity - O(n)
*/

class Solution {
public:
    int merge(vector<int>& nums, int left, int mid, int right) {
        int j=mid+1;
        int cnt_rev = 0;
        for (int i = left; i <= mid; i++) {
            long long store = 2;
            while ((j <= right) && (nums[i] > (long long)(store * nums[j]))) {
                j++;
            }
            
            cnt_rev += (j - (mid+1));
        }
        
        int i=left;
        j = mid+1;
        vector<int> tmp;
        
        while((i<=mid) && (j<=right)) {
            if(nums[i] > nums[j]) {
                tmp.push_back(nums[j++]);
            } else {
                tmp.push_back(nums[i++]);    
            }
        }
        
        while(i<=mid) {
            tmp.push_back(nums[i++]);
        }
        
        while(j<=right) {
           tmp.push_back(nums[j++]);
        }
        
        for(i=left; i<=right; i++) {
            nums[i] = tmp[i-left];
        }
        
        return cnt_rev;
    }
    
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        int mid = (left+right)/2;  
        
        int cnt_rev = mergeSort(nums, left, mid);
        cnt_rev += mergeSort(nums, mid+1, right);
            
        cnt_rev += merge(nums, left, mid, right);
        
        return cnt_rev;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};