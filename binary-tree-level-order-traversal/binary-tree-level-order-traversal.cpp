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
    vector<vector<int>> llevelOrder;
    void bfs(TreeNode* root,int level){
        if(!root){return;}
        if(llevelOrder.size() == level){
            llevelOrder.push_back({});
        }
        llevelOrder[level].push_back(root->val);
        bfs(root->left,level+1);
        bfs(root->right,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        bfs(root,0);
        return llevelOrder;
    }
};