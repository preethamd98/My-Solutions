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
    bool isValidBST(TreeNode* root,long mini=LONG_MIN,long max=LONG_MAX) {
        if(!root){return 1;}
        else if(mini < root->val and root->val < max){
            return isValidBST(root->left,mini,root->val) and isValidBST(root->right,root->val,max);
        }
        return 0;
    }
};