/*
    Time Complexity - O(n)
    Space Complexity - O(n)
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) {
            return NULL;
        }
        
        unordered_set<ListNode*> st;
        
        while(head != NULL) {
            if(st.find(head) != st.end()) {
                return head;
            }
            st.insert(head);
            head = head->next;
        }
        
        return NULL;
    }
};