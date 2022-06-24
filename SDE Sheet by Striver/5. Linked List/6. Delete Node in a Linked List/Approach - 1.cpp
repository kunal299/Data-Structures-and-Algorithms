/* 
    Time Complexity - O(1)
    Space Complexity - O(1)
*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        
        node->val = node->next->val;
        node->next = node->next->next;
    }
};