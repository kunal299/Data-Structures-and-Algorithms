/*
    Time Complexity - O(N*N)
    Space Complexity - O(N)
*/

class Solution {
public:
    int isPalindrome(int i, int j, string &s) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    int minCut(string s) {
        int n = s.length();

        vector<int> dp(n+1, -1);
        dp[n] = 0;

        for(int i=n-1; i>=0; i--) {
            int mini = 1e9;
            for(int k=i; k<n; k++) {
                if(isPalindrome(i, k, s)) {
                    int cuts = 1 + dp[k+1];
                    mini = min(mini, cuts);
                }
            }
            dp[i]=mini;
        }

        return dp[0] - 1;
    }
};