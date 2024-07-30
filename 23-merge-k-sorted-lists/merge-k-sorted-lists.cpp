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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;

        for(auto i:lists){
            if(i!=NULL)
            pq.push({i->val,i});
        }

        ListNode* ans = NULL;
        ListNode* res = ans;

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            if(ans==NULL){
                ListNode* t = new ListNode(temp.first);
                ans = t;
                res = ans;
            }
            else{
                ListNode* t = new ListNode(temp.first);
                ans->next = t;
                ans = ans->next;
            }
            temp.second = temp.second->next;
            if(temp.second!=NULL)
            pq.push({temp.second->val,temp.second});
        }
        return res;
    }
};