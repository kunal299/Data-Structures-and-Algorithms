/*
    Time Complexity - O(n * k)
    Space Complexity - O(1)
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        for(int i=0; i<k; i++) {
            ListNode* tmp = head;
            
            while(tmp->next->next != NULL) {
                tmp = tmp->next;
            }
            
            tmp->next->next = head;
            head = tmp->next;
            
            tmp->next = NULL;
        }
        
        return head;
    }
};