/*
    Time Complexity - O(m-1) or O(n-1)
    Space Complexity - O(1)
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int R = m-1;
        
        double res = 1;
        for(int i=1; i<=R; i++) {
            res = res*(N-R+i)/i;
        }
        
        return (int)res;
    }
};