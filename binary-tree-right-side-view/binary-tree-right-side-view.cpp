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
    vector<int> ans;
    void bfs(TreeNode* root,int level=0){
        if(!root){return;}
        if(ans.size()==level){ans.push_back(root->val);};
        bfs(root->right,level+1);
        bfs(root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        bfs(root);
        return ans;
    }
};