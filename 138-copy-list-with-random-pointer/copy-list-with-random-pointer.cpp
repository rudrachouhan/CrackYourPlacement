/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Solution without using HashMap 
        if(head==NULL)
        return head;

        Node* temp = head;
        while(temp!=NULL){
            Node* n = new Node(temp->val);
            n->next = temp->next;
            temp->next = n;
            temp = temp->next->next;
        }

        temp = head;
        // Copying random pointers
        while(temp!=NULL){
            if(temp->random!=NULL){
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        // Removing next links and creating new next links for the copied list
        temp = head;
        Node* ans = temp->next;
        while(temp!=NULL){
            Node* q = temp->next->next;
            if(temp->next->next!=NULL)
            temp->next->next = temp->next->next->next;
            temp->next = q;
            temp=q;
        }
        return ans;
    }
};