/*
    Time Complexity - O(n) + O(n-(n%k))
    Space Complexity - O(1)
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) {
            return head;
        }
        
        int size = 1;
        ListNode* tmp = head;
        
        while(tmp->next != NULL) {
            size++;
            tmp = tmp->next;
        }
        
        size -= (k%size);
        
        tmp->next = head;
    
        while(size--) tmp = tmp->next;
        
        head = tmp->next;        
        tmp->next = NULL;
        
        return head;
        
    }
};