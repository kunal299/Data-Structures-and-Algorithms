/*
    Time Complexity - O(n^2)
    Space Complexity - O(1)
*/

class Solution {
public:
    string getPermutation(int n, int k) {

        int fact = 1;
        string nums = "";
        for(int i=1; i<=n; i++) {
            fact *= i;
            nums += (i+'0');
        }
        
        fact /= n;
        
        string ans = "";
        --k;
       
        while(nums.size() != 0) {
            
            int idx = k/fact;
            k = k % fact;
            
            ans += nums[idx];
            nums.erase(nums.begin()+idx);
            
            if(nums.size()!=0) {
                fact /= (nums.size());
            }
            
        }
        
        return ans;
        
    }
};