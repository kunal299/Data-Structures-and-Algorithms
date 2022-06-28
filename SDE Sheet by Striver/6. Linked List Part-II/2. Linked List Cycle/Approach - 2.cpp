/*
    Time Complexity - O(n)
    Space Complexity - O(1)
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while((fast->next!=NULL) && (fast->next->next!=NULL)) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};