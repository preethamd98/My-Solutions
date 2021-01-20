/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct compare{
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> heap;
        for(auto i:lists){if(i!=NULL){heap.push(i);}}
        ListNode* ll = new ListNode(0);
        ListNode* ret = ll;
        while(heap.size()>0){
            ListNode* t = heap.top();heap.pop();
            ll->next = new ListNode(t->val);
            ll = ll->next;
            t = t->next;
            if(t!=NULL){
                heap.push(t);
            }
        }
        return ret->next;
    }
};
