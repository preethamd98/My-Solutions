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
struct BSTNODE{
    bool isBST;
    int size;
    int min;
    int max;
    BSTNODE(bool bst,int s,int mi,int ma): isBST(bst),size(s),min(mi),max(ma){}
};
​
typedef struct BSTNODE BSTNODE;
class Solution {
public:
    BSTNODE postOrder(TreeNode* root){
        if(!root){return BSTNODE(1,0,INT_MAX,INT_MIN);}
        auto left = postOrder(root->left);
        auto right = postOrder(root->right);
        if(left.isBST == true and right.isBST == true){
            if(root->val > left.max and root->val < right.min){
                return BSTNODE(true,left.size+right.size+1,min(root->val,left.min),max(root->val,right.max));
            }
        }
        return BSTNODE(false,max(left.size,right.size),-1,-1);
    }
    int largestBSTSubtree(TreeNode* root) {
        if(!root){return 0;}
        auto val = postOrder(root);
        return val.size;
    }
};
​
​
