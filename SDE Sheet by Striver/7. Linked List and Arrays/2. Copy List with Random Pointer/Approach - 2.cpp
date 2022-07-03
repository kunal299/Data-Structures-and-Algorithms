/*
    Time Complexity - O(n) + O(n) + O(n) ~ O(n)
    Space Complexity - O(1)
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* tmp = head;
        Node* nex = head;
        
        while(tmp != NULL) {
            Node* newNode = new Node(tmp->val);
            nex = tmp->next;
            
            tmp->next = newNode;
            newNode->next = nex;
            
            tmp = nex;
        }
        
        tmp = head;
        
        while(tmp != NULL) {
            if(tmp->random != NULL) {
                tmp->next->random = tmp->random->next;   
            }
            tmp = tmp->next->next;
        }        
        
        tmp = head;
        
        Node* dmy = new Node(0);
        Node* res = dmy;
        
        while(tmp != NULL) {
            nex = tmp->next->next;
            
            dmy->next = tmp->next;
            
            tmp->next = nex;
            
            dmy = dmy->next;
            tmp = nex;
        }
        
        return res->next;
    }
};