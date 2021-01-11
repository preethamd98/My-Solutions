​
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* first = head;
        for(int i=0;i<k-1;i++){
            fast = fast->next;
        }
        first = fast;
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        swap(first->val,slow->val);
        return head;
    }
};
