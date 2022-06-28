/*
    Time Complexity - O(n+m) + O(abs(n-m)) + O(min(m,n))
    Space Complexity - O(1) 

    where n is the length of list1
          m is the length of list2
*/

//Using the logic of Difference in lengths

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* dummy1 = headA;
        ListNode* dummy2 = headB;
        
        int sz1 = 0,sz2 = 0;
        while(dummy1 != NULL) {
            sz1++;
            dummy1 = dummy1->next;
        }
        
        while(dummy2 != NULL) {
            sz2++;
            dummy2 = dummy2->next;
        }
        
        int storeMin = min(sz1, sz2);
        int storeMax = max(sz1, sz2);
        
        int diff = storeMax - storeMin;
        
        dummy1 = headA;
        dummy2 = headB;
        
        while(diff--) {
            if(sz1==storeMax) {
                dummy1 = dummy1->next;
            } else {
                dummy2 = dummy2->next;
            }
        }
        
        while((dummy1!=NULL) || (dummy2!=NULL)) {
            if(dummy1 == dummy2) {
                return dummy1;
            }
            dummy1 = dummy1->next;
            dummy2 = dummy2->next;
        }
        
        return NULL;
    }
};