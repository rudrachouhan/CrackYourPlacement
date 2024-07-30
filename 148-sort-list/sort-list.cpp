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
    ListNode* sortList(ListNode* head) {
        if(head==NULL)
        return NULL;

        ListNode* temp = head;
        ListNode* ans = sortList(head->next);

        temp->next = NULL;
        ListNode* temp2 = ans;
        ListNode* prev=NULL;
        while(temp2!=NULL && temp->val > temp2->val){
            prev=temp2;
            temp2=temp2->next;
        }
        if(prev){
        prev->next = temp;
        temp->next = temp2;
        }
        else{
            temp->next = temp2;
            ans = temp;
        }

        return ans;
    }
};