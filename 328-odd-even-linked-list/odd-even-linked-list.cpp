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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
        return NULL;

        int count = 1;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* n = head->next;
        ListNode* temp = head;

        while(curr!=NULL){
            if(count%2==1 && count!=1){
                prev->next = curr->next;
                curr->next = n;
                temp->next = curr;
                temp = curr;
                curr = prev->next;
                count++;
            }
            else{
            prev=curr;
            curr = curr->next;
            count++;
            }
        }
        return head;
    }
};