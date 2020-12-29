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
    void helper(TreeNode* root,int height=0){
        if(!root){return;}
        if(V.size()<=height){V.push_back(root->val);}
        else{V[height] = max(V[height],root->val);} 
        helper(root->left,height+1);
        helper(root->right,height+1);
    }
        
    vector<int> largestValues(TreeNode* root) {
        helper(root);
        return V;
    }
};
