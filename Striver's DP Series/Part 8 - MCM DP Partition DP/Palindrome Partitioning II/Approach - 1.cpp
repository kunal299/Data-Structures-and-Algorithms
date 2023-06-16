/*
    Time Complexity - O(N*N)
    Space Complexity - O(N) + O(N)
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

    int helper(int i, int n, string &s, vector<int> &dp) {
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int mini = 1e9;
        for(int k=i; k<n; k++) {
            if(isPalindrome(i, k, s)) {
                int cuts = 1 + helper(k+1, n, s, dp);
                mini = min(mini, cuts);
            }
        }

        return dp[i]=mini;
    }

    int minCut(string s) {
        int n = s.length();

        vector<int> dp(n+1, -1);
        return helper(0, n, s, dp)-1;
    }
};