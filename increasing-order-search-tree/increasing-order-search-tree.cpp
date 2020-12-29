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
    TreeNode* newNode = NULL;
    TreeNode* currentNode = NULL;
    TreeNode* increasingBST(TreeNode* root) {
        if(!root){return NULL;}
        increasingBST(root->left);
        if(newNode==NULL){
            newNode = new TreeNode(root->val);
            currentNode = newNode;
        }
        else{
            currentNode->right = new TreeNode(root->val);
            currentNode = currentNode->right;
        }
        increasingBST(root->right);
        return newNode;
    }
};
