/*
    Time Complexity - O(2*n)
    Space Complexity - O(n)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        set<char> st;
        
        int l = 0;
        int r = 0;
        int len = 0; 
        
        while(r<n) {
            if(!st.count(s[r])) {
                st.insert(s[r]);
                len = max(len, r-l+1);
                r++;
            } else {
                st.erase(s[l]);
                l++;
            }
        }
        
        return len;
    }
};