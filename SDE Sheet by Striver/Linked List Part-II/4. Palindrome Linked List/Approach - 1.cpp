/*
    Time Complexity - O(n)
    Space Complexity - O(n)
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        ListNode* tmp = head;
        
        while(tmp != NULL) {
            v.push_back(tmp->val);
            tmp = tmp->next;
        }
        
        int s = 0, e = v.size()-1;
        
        while(s < e) {
            if(v[s] != v[e]) {
                return false;
            }
            s++;
            e--;
        }
        
        return true;
    }
};