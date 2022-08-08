/*
    Time Complexity - O(n/2) + O(n/2) + O(n/2)  (reverse + middle + palindrome)
    Space Complexity - O(1)
*/

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nex;
        
        while(curr != NULL) {
            nex = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = nex;
        }
        
        head = prev;
        return head;
    }
    
    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while((fast->next!=NULL) && (fast->next->next!=NULL)) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        
        ListNode* mid = middle(head);
        
        mid->next = reverse(mid->next);
        mid = mid->next;
        
        while(mid != NULL) {
            if(head->val != mid->val) {
                return false;
            }
            
            head = head->next;
            mid = mid->next;
        }
        
        return true;
    }
};