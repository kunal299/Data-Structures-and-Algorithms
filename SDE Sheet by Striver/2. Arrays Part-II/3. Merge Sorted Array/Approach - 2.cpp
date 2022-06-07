/*
    Time Complexity - O(m * n)
    Space Complexity - O(1)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) {
            return;
        }
        
        for(int i=0; i<m; i++) {
            
            if(nums1[i] > nums2[0]) {
                swap(nums1[i], nums2[0]);
            }
            
            int store = nums2[0];
            
            int j;
            for(j=1; j<n && nums2[j]<store; j++) {
                nums2[j-1] = nums2[j];
            }
            
            nums2[j-1] = store;  
            
        }
        
        int idx1 = m, idx2 = 0;
        while(n--) {
            nums1[idx1] = nums2[idx2];
            idx1++;
            idx2++;
        }
    }
};