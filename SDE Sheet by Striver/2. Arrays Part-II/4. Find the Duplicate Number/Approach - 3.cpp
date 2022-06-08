/*
    Time Complexity - O(n)
    Space Complexity - O(1)
*/

//Using Tortoise Method's Approach 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        //Initializing slow and fast pointers
        int slow = nums[0];
        int fast = nums[0];
        
        /*
          Steps taken each time:
          Fast pointer - 2
          Slow pointer - 1
        */
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while(slow != fast);
        
        //Now, we just allow fast pointer to take only 1 step at a time
        fast = nums[0];
        while(fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        
        return slow;
    }
};