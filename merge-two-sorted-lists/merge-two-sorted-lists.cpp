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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ll = new ListNode(0);
        ListNode* first = ll;
        while(l1!=NULL and l2!=NULL){
            if(l1->val <= l2->val){
                ll->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else{
                ll->next = new ListNode(l2->val);
                l2 = l2->next;
            } 
            ll = ll->next;
        }
        while(l1!=NULL){
            ll->next = new ListNode(l1->val);
            ll = ll->next;
            l1 = l1->next;
        }
        while(l2!=NULL){
            ll->next = new ListNode(l2->val);
            ll = ll->next;
            l2 = l2->next;
        }
        return first->next;
    }
};