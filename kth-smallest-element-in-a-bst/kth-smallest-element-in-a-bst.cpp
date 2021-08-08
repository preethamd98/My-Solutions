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
    vector<int> inOrder;
    void traverse(TreeNode* root){
        if(!root){return;}
        traverse(root->left);
        inOrder.push_back(root->val);
        traverse(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        traverse(root);
        return inOrder[k-1];
    }
};