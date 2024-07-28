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
    ListNode* revList(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        
      
        ListNode* temp= revList(head->next);
     
        head->next->next=head;
        head->next=NULL;
 
        return temp;

    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* prev=NULL;

        int l=1;
        ListNode* temp=head;
        while(l<left){
            prev=temp;
            temp=temp->next;
            l++;
        }

        int r=1;
        ListNode* temp2=head;
        while(r<right){
            temp2=temp2->next;
            r++;
        }
        
        ListNode* last=NULL;
        if(temp2->next){
            last=temp2->next;
            temp2->next=NULL;
        }

        if(prev){
            prev->next=revList(temp);
        }
        else{
            head=revList(temp);
        }

        temp->next=last;
        return head;
        
    }
};