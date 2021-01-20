/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
​
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return root;
        }
        else if(root->val == p->val){
            return root;
        }
        else if(root->val == q->val){
            return root;
        }
        if(p->val < root->val and q->val < root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        if(q->val > root->val and p->val > root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left and right){
            return root;
        }
        else if(left==NULL){
            return right;
        }
        return left;
    }
};
