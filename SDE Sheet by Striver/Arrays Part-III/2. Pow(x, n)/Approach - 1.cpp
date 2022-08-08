/*
    Time Complexity - O(n)
    Space Complexity - O(1)
*/

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long num = n;
        if (num < 0) num = -1 * num;

        for (int i = 0; i < num; i++) {
            ans = ans * x;
        }

        if (n < 0) ans = (double)(1.0) / (double)(ans);
        return ans;
    }
};