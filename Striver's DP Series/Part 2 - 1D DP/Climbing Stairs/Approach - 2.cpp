/*  
    Time Complexity - O(n)
    Space Commplexity - O(1)
*/

//Using Tabulation(Bottom-Up Approach)
int countDistinctWays(int nStairs) {
    int prev = 1, prev2 = 1;
    
    for(int i=2; i<=nStairs; i++) {
        int curr = (prev + prev2)%1000000007;
        prev2 = prev;
        prev = curr;
    }
    
    return prev;
}