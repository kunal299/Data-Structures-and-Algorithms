/*
    Time Complexity - O(n) + O(n) ~ O(n)
    Space Complexity - O(n)
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* tmp = head;
        map<Node*, Node*> mp;
        
        while(tmp != NULL) {
            Node* newNode = new Node(tmp->val);
            mp[tmp] = newNode;
            
            tmp = tmp->next;
        }
        
        tmp = head;
        
        while(tmp != NULL) {
            mp[tmp]->next = mp[tmp->next];
            mp[tmp]->random = mp[tmp->random];    
            
            tmp = tmp->next;
        }
        
        return mp[head];
    }
};