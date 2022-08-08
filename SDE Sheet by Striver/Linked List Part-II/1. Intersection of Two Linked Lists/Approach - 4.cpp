/*
    Time Complexity - O(2 * max(n,m))
    Space Complexity - O(1) 

    where n is the length of list1
          m is the length of list2
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* dummy1 = headA;
        ListNode* dummy2 = headB;
        
        while(dummy1 != dummy2) { 
            dummy1 = dummy1->next;
            dummy2 = dummy2->next;
            
            if((dummy1==NULL) && (dummy2!=NULL)) {
                dummy1 = headB;
            }
            
            if((dummy2==NULL) && (dummy1!=NULL)) {
                dummy2 = headA;
            }
        }
        
        return dummy1;
    }
};