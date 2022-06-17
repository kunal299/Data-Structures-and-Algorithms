/*
    Time Complexity - O(n)
    Space Complexity - O(n)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) {
            return 0;
        }
        
        set<int> st(nums.begin(), nums.end());
        
        int maxi = 0;
        for(auto &it: st) {
            if(st.count(it-1)==false) {
                int cnt = 1;
                int num = it+1;
                
                while(st.count(num)==true) {
                    cnt++;
                    num++;
                }
                
                maxi = max(maxi, cnt);
            }
        }
        
        return maxi;
    }
};