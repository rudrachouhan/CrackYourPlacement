/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        int l1 = 0, l2=0;
        while(temp1!=NULL){
            l1++;
            temp1=temp1->next;
        }

        while(temp2!=NULL){
            l2++;
            temp2=temp2->next;
        }

        temp1=headA;
        temp2=headB;
        if(l1>l2){
            int diff = l1-l2;
            int cnt =0;
            while(cnt<diff){
                temp1 = temp1->next;
                cnt++;
            }
        }
        else{
            int diff = l2-l1;
            int cnt =0;
            while(cnt<diff){
                temp2 = temp2->next;
                cnt++;
            }
        }

        while(temp1!=NULL && temp2!=NULL){
            if(temp1==temp2)
            return temp1;
            temp1= temp1->next;
            temp2=temp2->next;
        }

        return NULL;
    }
};