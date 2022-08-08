/*
    Time Complexity - O(n^2)
    Space Complexity - O(n)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int len = 0;
        
        for (int i=0; i<n; i++){
            unordered_set<int> st;
            for (int j=i; j<n; j++){
                if (st.count(s[j])) {
                    len = max(len, j - i);
                    break;
                }
                st.insert(s[j]);
            }
        }
        
    return len;
    }
};