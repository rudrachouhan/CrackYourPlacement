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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            int count=1;
            while(temp->next!=NULL && temp->val==temp->next->val){
                count++;
                temp=temp->next;
            }
            if(count>1){
                if(!prev){
                    head = temp->next;
                }
                else{
                    prev->next = temp->next;
                }
                temp=temp->next;
                continue;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};