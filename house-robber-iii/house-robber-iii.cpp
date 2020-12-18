/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,int> dp;
    int rob(TreeNode* root) {
        if(root==NULL){return 0;}
        if(dp.find(root)!=dp.end()){return dp[root];}
        int withoutCurrentNode = rob(root->left) + rob(root->right);
        int withCurrentNode = root->val +((root->left!=NULL)?(rob(root->left->left) + rob(root->left->right)):0)
                                + ((root->right!=NULL)?(rob(root->right->left)+rob(root->right->right)):0);
        return dp[root] = max(withoutCurrentNode,withCurrentNode);
    }
};
