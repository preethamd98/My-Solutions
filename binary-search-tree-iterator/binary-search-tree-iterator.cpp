/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> callstack;
    BSTIterator(TreeNode* root) {
        while(root!=NULL){
            callstack.push(root);
            root = root->left;
        }
    }
    
    int next() {
        int val = -1;
        if(hasNext()){
            TreeNode* temp = callstack.top();
            val = temp->val;
            callstack.pop();
            temp = temp->right;
            while(temp!=NULL){
                callstack.push(temp);
                temp = temp->left;
            }
        }
        return val;
    }
    
    bool hasNext() {
        if(callstack.size()==0){
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */