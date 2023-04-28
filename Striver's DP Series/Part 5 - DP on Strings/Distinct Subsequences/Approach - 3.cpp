/*
    Time Complexity - O(M*N)
    Space Complexity - O(N)
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        vector<int> prev(n+1, 0);
        prev[0] = 1;

        for(int i=1; i<=m; i++) {

            //Reverse direction
            for(int j=n; j>=1; j--) {
                if(s[i-1] == t[j-1]) {
                    prev[j] = (prev[j-1] + prev[j])%1000000007;
                } else {
                    prev[j] = prev[j];
                }
            }
        }

        return prev[n];
    }
};