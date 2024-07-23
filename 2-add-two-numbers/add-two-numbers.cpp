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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int le1 =0,le2 =0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(temp1!=NULL){
            le1++;
            temp1= temp1->next;
        }
        while(temp2!=NULL){
            le2++;
            temp2= temp2->next;
        }
        temp1 = l1;
        temp2 = l2;
        int carry = 0;
        while(temp1!=NULL || temp2!=NULL){
            int sum = carry;
            if(temp1!=NULL)
            sum+= temp1->val;
            if(temp2!=NULL)
            sum+= temp2->val;
            if(sum>9){
                carry = 1;
            }
            else
            carry = 0;
            if(le1>le2){
                temp1->val = sum%10;
            }
            else{
                temp2->val = sum% 10;
            }
            if(temp1!=NULL)
            temp1 = temp1->next;
            if(temp2!=NULL)
            temp2 = temp2->next;
        }
        temp1 =l1;
        temp2=l2;
        if(carry == 1){
            if(le1>le2){
                while(temp1->next!=NULL){
                    temp1 = temp1->next;
                }
                ListNode* n = new ListNode(1);
                temp1->next = n;
            }
            else{
                while(temp2->next!=NULL){
                    temp2 = temp2->next;
                }
                ListNode* n = new ListNode(1);
                temp2->next = n;
            }
        }
        if(le1>le2){
            return l1;
        }
        else{
            return l2;
        }
    }
};