/*
    Time Complexity - O(M*N)
    Space Complexity - O(N)
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector<int> prev(n+1, 0), curr(n+1, 0);

        for(int j=0; j<=n; j++) {
            prev[j] = j;
        }

        for(int i=1; i<=m; i++) {
            curr[0] = i;
            for(int j=1; j<=n; j++) {

                if(word1[i-1] == word2[j-1]) {
                    curr[j] = prev[j-1];
                } else {
                    curr[j] = 1 + min(curr[j-1], min(prev[j], prev[j-1]));
                }

            }
            prev = curr;
        }
        return prev[n];
    }
};