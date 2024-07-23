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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int size = 0;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        int todel = size-n;
        if(todel==0)
        return head->next;
        int t =1;
        temp = head;
        while(t<todel){
            temp = temp->next;
            t++;
        }
        ListNode* ne = temp->next;
        temp->next = ne->next;
        ne->next = NULL;
        delete ne;

        return head; 
    }
};