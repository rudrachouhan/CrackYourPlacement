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
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr = NULL;
        ListNode* n = head;

        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            if(temp->val<x){
                if(curr==NULL){
                    if(temp==head){
                        curr=head;
                        n=head->next;
                    }
                    else{
                    ListNode* temp2 = temp->next;
                    prev->next = temp->next;
                    temp->next = n;
                    curr = temp;
                    head=temp;
                    temp = temp2;
                    continue;
                    }
                }
                else if(n==temp){
                    curr=temp;
                    n=temp->next;
                }
                else{
                    ListNode* temp2 = temp->next;
                    prev->next = temp->next;
                    temp->next = n;
                    curr->next = temp;
                    curr = temp;
                    temp = temp2;
                    continue;
                }
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};