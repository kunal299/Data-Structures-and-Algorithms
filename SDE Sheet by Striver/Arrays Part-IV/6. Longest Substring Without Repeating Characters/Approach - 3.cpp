/*
    Time Complexity - O(n)
    Space Complexity - O(n)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector < int > mp(256, -1);
        
        int l = 0;
        int r = 0;
        int len = 0; 
        
        while(r<n) {
            if(mp[s[r]] != -1) {
                l = max(l, mp[s[r]] + 1);
            } 
            
            len = max(len, r-l+1);
            mp[s[r]] = r;
            r++;
        }
        
        return len;
    }
};