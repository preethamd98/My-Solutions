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
class Solution {
public:
    int counter = 0;
    void helper(TreeNode* root,int maxi){
        if(!root){return;}
        maxi = max(root->val,maxi);
        if(root->val>=maxi){
            counter++;
        }
        helper(root->left,maxi);
        helper(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        if(!root){return 0;}
        helper(root,root->val);
        return counter;
    }
};