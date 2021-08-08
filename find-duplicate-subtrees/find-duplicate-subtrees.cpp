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
    vector<TreeNode*> ans;
    unordered_map<string,int> M;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    string dummy = dfs(root);
    return ans;
    }
    string dfs(TreeNode* root){
        if(!root){return "";}
        string ss = to_string(root->val) + "," + dfs(root->left) + "," + dfs(root->right);
        M[ss]++;
        if(M[ss] == 2){ans.push_back(root);}
        return ss;
    }
};