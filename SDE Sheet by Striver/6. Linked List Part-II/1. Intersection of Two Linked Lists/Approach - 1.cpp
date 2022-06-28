/*
    Time Complexity - O(n*m)
    Space Complexity - O(1)

    where n is the length of list1
          m is the length of list2
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headB != NULL) {
            ListNode* tmp = headA;
            
            while(tmp != NULL) {
                if(tmp == headB) return headB;
                tmp = tmp->next;
            }
            
            headB = headB->next;
        }
        
    return NULL;
    }
};