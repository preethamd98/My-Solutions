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
    int index = 0;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int left,int right){
        if(left > right){return nullptr;}
        int pivot = left;
        while(inorder[pivot]!=preorder[index]){pivot++;}
        index++;
        TreeNode* root = new TreeNode(inorder[pivot]);
        root->left = helper(preorder,inorder,left,pivot-1); 
        root->right = helper(preorder,inorder,pivot+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* tree = helper(preorder,inorder,0,preorder.size()-1);
        return tree;
    }
};