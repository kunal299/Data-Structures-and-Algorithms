/*
    Time Complexity - O(n)
    Space Complexity - O(1)
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1) {
            return head;
        }
        
        int sz = 0;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode *pre = dummy, *curr = dummy, *nex = dummy;
        
        while(curr->next != NULL) {
            sz++;
            curr = curr->next;
        }
        
        while(sz >= k) {
            curr = pre->next;
            nex = curr->next;
            
            for(int i=1; i<k; i++) {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            
            sz -= k;
            pre = curr;
        }
        
        return dummy->next;
    }
};