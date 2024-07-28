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
    ListNode* reverse(ListNode* head){
        ListNode *p, *q;
        p=head, q=NULL;
        
        while(p!=NULL){
            ListNode* on=p->next; 
            p->next=q; 
            q=p;
            p=on;
        }
        return q;
    }
    
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode* p=reverse(head1);
        ListNode* q=reverse(head2);
        
        ListNode *head, *last;
        head=last=new ListNode(-1);
        
        int carry=0;
        while(p!=NULL || q!=NULL){
            int d=(p!=NULL ? p->val:0) + (q!=NULL ? q->val:0) + carry;
            
            ListNode *temp=new ListNode(d%10);
            last->next=temp;
            last=temp;
            
            carry=d/10;
            
            if(p) p=p->next;
            if(q) q=q->next;
        }
        
        if(carry!=0){
            ListNode *temp=new ListNode(carry);
            last->next=temp;
            last=temp;
        }
        
        head=head->next;
        head=reverse(head);
        
        return head;
    }
};