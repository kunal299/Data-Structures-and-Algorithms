/*
    Time Complexity - O(N*N)
    Space Complexity - O(N)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> next(n+1, 0);
        vector<int> curr(n+1, 0);

        for(int i=n-1; i>=0; i--) {
            for(int prev=i-1; prev>=-1; prev--) {

                int take = 0, notTake = 0;

                if(prev == -1 || nums[i] > nums[prev]) {
                    take = 1 + next[i+1];
                } 

                notTake = next[prev+1]; 

                curr[prev+1] = max(take, notTake);
            }
            next = curr;
        }

        return curr[0];
    }
};