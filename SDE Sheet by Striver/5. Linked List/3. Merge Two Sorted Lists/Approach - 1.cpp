/*
    Time Complexity - O(n+m)
    Space Complexity - O(n+m)

    where n is the size of list1
          m is the size of list2
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL) {
            return NULL;
        } else if(list1==NULL) {
            return list2;
        } else if(list2==NULL) {
            return list1;
        }
        
        ListNode* list3 = new ListNode();
        ListNode* ans = list3;
        
        while((list1 != NULL) && (list2 != NULL)) {
            ListNode* new_node = new ListNode();
            if(list1->val > list2->val) {
                list3->val = list2->val;
                list2 = list2->next;
            } else {
                list3->val = list1->val;
                list1 = list1->next;
            }
            list3->next = new_node;
            list3 = list3->next;
        }
        
        while(list1 != NULL) {
            list3->val = list1->val;
            list1 = list1->next;
            if(list1 != NULL) {
                ListNode* new_node = new ListNode();
                list3->next = new_node;
                list3 = list3->next;
            }
        }

        while(list2 != NULL) {
            list3->val = list2->val;
            list2 = list2->next;
            if(list2 != NULL) {
                ListNode* new_node = new ListNode();
                list3->next = new_node;
                list3 = list3->next;
            }
        }
        
        return ans;
        
    }
};