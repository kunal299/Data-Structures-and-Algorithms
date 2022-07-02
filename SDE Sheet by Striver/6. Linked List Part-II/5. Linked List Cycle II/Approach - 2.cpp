/*
    Time Complexity - O(n)
    Space Complexity - O(1)
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) {
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while((fast->next!=NULL) && (fast->next->next!=NULL)) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow==fast) {
                fast = head;
                while(fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        } 
        
        return NULL;
    }
};