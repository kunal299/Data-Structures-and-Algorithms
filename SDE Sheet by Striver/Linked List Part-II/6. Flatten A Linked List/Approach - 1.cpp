/*
    Time Complexity - O(n)
    Space Complexity - O(1)
*/

#include <bits/stdc++.h> 

Node* mergeTwoLists(Node* a, Node* b) {
    Node* tmp = new Node(0);
    Node* res = tmp;
    
    while((a!=NULL) && (b!=NULL)) {
        if(a->data < b->data) {
            tmp->child = a;
            a = a->child;
        } else {
            tmp->child = b;
            b = b->child;
        }
        tmp = tmp->child;
    }
    
    if(a != NULL) {
        tmp->child = a;
    } else {
        tmp->child = b;
    }
    
    return res->child;
}

Node* flattenLinkedList(Node* head) 
{
    if(head==NULL || head->next==NULL) {
        return head;
    }
    
    head->next = flattenLinkedList(head->next);
    head = mergeTwoLists(head, head->next);
    
    return head;
}
