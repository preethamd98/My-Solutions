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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root || !root->left){return root;}
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        TreeNode* current = upsideDownBinaryTree(root->left);
        left->right = root;
        left->left = right;
        root->left = NULL;
        root->right = NULL;
        return current;
    }
};