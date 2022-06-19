/*
	Time Complexity - O(n)
	Space Complexity - O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* nextt;
        ListNode* curr = head;
        
        while(curr != NULL) {
            nextt = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = nextt;
        }
        
        head = prev;
        return head;
    }
};