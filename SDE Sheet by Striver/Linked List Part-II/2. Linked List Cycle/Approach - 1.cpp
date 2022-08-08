/*
    Time Complexity - O(n)
    Space Complexity - O(n)
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return NULL;
        
        unordered_set<ListNode*> st;
        
        while(head != NULL) {
            if(st.find(head) != st.end()) {
                return true;
            }
            st.insert(head);
            head = head->next;
        }
        
        return NULL;
    }
};