/*
    Time Complexity - O(2n) 
    Space Complexity - O(1)    
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = NULL;
        ListNode* dummy = head;
        int size = 0;
        
        while(dummy != NULL) {
            dummy = dummy->next;
            size++;
        }
        
        if(size==n) {
            return head->next;
        }
        
        dummy = head;
        
        int cnt = 0;
        while(dummy != NULL) {
            cnt++;
            tmp = dummy;
            dummy = dummy->next;
            
            if(cnt==size-n) {
                tmp->next = dummy->next;
                break;
            }
        }
        
        return head;
    }
};