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

    ListNode* reverseLL(ListNode* head){
        if(head==NULL || head->next==NULL)
        return head;

        ListNode* n = head->next;
        ListNode* ans = reverseLL(head->next);
        n->next = head;
        head->next = NULL;

        return ans;
    }

    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
        return true;

        ListNode* slow = NULL;
        ListNode* fast = head;

        while(fast!=NULL){
            if(slow==NULL)
            slow=head;
            else
            slow = slow->next;
            fast = fast->next;
            if(fast){
                fast=fast->next;
            }
        }
        
        slow->next = reverseLL(slow->next);
        slow=slow->next;
        ListNode* temp = head;
        while(slow!=NULL){
            if(slow->val!=temp->val)
            return false;
            slow=slow->next;
            temp=temp->next;
        }
        return true;
    }
};