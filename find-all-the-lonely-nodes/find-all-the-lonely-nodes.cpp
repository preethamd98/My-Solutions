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
    vector<int> V;
    void dfs(TreeNode* root){
        if(!root){return;}
        if(((root->left==NULL) and (root->right!=NULL))){
            V.push_back(root->right->val);
        }
        else if(((root->left!=NULL) and (root->right==NULL))){
            V.push_back(root->left->val);
        }
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> getLonelyNodes(TreeNode* root) {
        dfs(root);
        return V;
    }
};
