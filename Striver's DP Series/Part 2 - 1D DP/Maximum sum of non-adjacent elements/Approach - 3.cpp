/*
    Time Complexity - O(n)
    Space Complexity - O(1)
*/

//Space Optimization
int maximumNonAdjacentSum(vector<int> &nums){
    int prev = nums[0], prev2 = 0;
    
    for(int i=1; i<nums.size(); i++) {
        int picked = nums[i];
        if(i>=1) {
             picked += prev2;   
        }
        int unpicked = 0 + prev;
        int curr = max(picked, unpicked);
        prev2 = prev;
        prev = curr;
    }
    
    return prev;
}