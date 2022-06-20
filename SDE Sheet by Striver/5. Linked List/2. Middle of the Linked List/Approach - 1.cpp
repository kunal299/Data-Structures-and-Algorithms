/*
    Time Complexity - O(n) + O(n/2)
    Space Complexity - O(1)
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode* tmp = head;
        
        while(tmp != NULL) {
            cnt++;
            tmp = tmp->next;
        }
        
        tmp = head;
        
        for(int i=0; i<cnt/2; i++) {
            tmp = tmp->next;
        }
        
        return tmp;
    }
};