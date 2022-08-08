/*
    Time Complexity - O(n)
    Space Complexity - O(1)    
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = new ListNode();
        tmp->next = head;
        ListNode* fast_ptr = tmp;
        ListNode* slow_ptr = tmp;
        
        for(int i=1; i<=n; i++) {
            fast_ptr = fast_ptr->next;
        }
        
        while(fast_ptr->next != NULL) {
            fast_ptr = fast_ptr->next;
            slow_ptr = slow_ptr->next;
        }
        
        slow_ptr->next = slow_ptr->next->next;
        
        return tmp->next;
    }
};