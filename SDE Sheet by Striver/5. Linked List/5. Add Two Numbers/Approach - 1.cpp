/*
    Time Complexity - O(max(m, n))
    Space Complexity - O(max(m, n))

    where m and n are the length of list1 and list2 resp.
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        
        while((l1!=NULL) || (l2!=NULL) || carry!=0) {
            int sum = 0;
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            sum += carry;
            carry = sum/10;
            
            ListNode* newNode = new ListNode();
            newNode->val = (sum%10);
            dummy->next = newNode;
            
            dummy = dummy->next;
        }
        
        return temp->next;
    }
};