        while(size1 > 0 and size2 > 0) {
            int val = 0;
            if(size1 >= size2) {
                val += l1->val;
                l1 = l1->next;
                size1--;
            }
            if(size2 > size1) {
                val += l2->val;
                l2 = l2->next;
                size2--;
            }
            ListNode* curr = new ListNode(val);
            curr->next = head;
            head = curr;
        }
        ListNode* currNode = head;
        ListNode* res = NULL;
        int carry = 0;
        while(currNode != NULL) {
            int currVal = (currNode->val + carry) % 10;
            carry = (currNode->val + carry) / 10;
            ListNode* newCurrNode = new ListNode(currVal);
            newCurrNode->next = res;
            res = newCurrNode;
            currNode = currNode->next;
        }
        if(carry) {
            ListNode* newCurrNode = new ListNode(carry);
            newCurrNode->next = res;
            res = newCurrNode;
        }
        return res;
    }
};
