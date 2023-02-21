/*
    Time Complexity - O(m*n)
    Space Complexity - O(n)
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<int> prev(n+1, 0), curr(n+1, 0);
    
        //Base case is covered as we have already initialized it with zero in the previous line
    
        for(int idx1=1; idx1<=m; idx1++) {
            for(int idx2=1; idx2<=n; idx2++) {

                if(text1[idx1-1] == text2[idx2-1]) {
                    curr[idx2] = 1 + prev[idx2-1];
                } else {
                    curr[idx2] = max(prev[idx2], curr[idx2-1]);
                }

            }

            prev = curr;
        }

        return curr[n];
    }
};