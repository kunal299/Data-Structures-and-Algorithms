/*
    Time Complexity - O(m * logm)
    Space Complexity - O(1)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int gap = ceil(float(m+n)/2.0);
        while(gap > 0) {
            
            int ptr1 = 0;
            int ptr2 = gap;
            
            while(ptr2 < m+n) {
                
                if(ptr2<m) {
                    if(ptr1<m) {
                        if(nums1[ptr1] > nums1[ptr2]) {
                            swap(nums1[ptr1], nums1[ptr2]);
                        }
                    } 
                } else {
                    if(ptr1<m) {
                        if(nums1[ptr1] > nums2[ptr2-m]) {
                            swap(nums1[ptr1], nums2[ptr2-m]);
                        }
                    } else {
                        if(nums2[ptr1-m] > nums2[ptr2-m]) {
                            swap(nums2[ptr1-m], nums2[ptr2-m]);
                        }
                    }
                }
                
                ptr1++;
                ptr2++;
                
            }
            
            if (gap == 1) {
                gap = 0;
            } else {
                gap = ceil((float) gap / 2.0);
            }
        }
        
        int idx = 0;
        for(int i=m; i<m+n; i++) {
            nums1[i] = nums2[idx];
            idx++;
        }
        
    }
};