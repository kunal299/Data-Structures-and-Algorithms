/*
    Time Complexity - O(n+m)
    Space Complexity - O(n)

    where n is the length of list1
          m is the length of list2
*/

//Using Hashing

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> st;
        ListNode* temp = headA;
        
        while(temp != NULL) {
            st.insert(temp);
            temp = temp->next;
        }
        
        temp = headA;
        
        while(headB != NULL) {
            if(st.find(headB) != st.end()) {
                return headB;
            }
            headB = headB->next;
        }
        
        return NULL;
        
    }
};