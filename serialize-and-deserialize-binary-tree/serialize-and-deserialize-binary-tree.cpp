/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr){return "NULL";}
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return unpack(ss);
    }
private:
    TreeNode* unpack(istringstream &ss){
        string token;
        getline(ss,token,',');
        if(token == "NULL"){return nullptr;}
        TreeNode *t = new TreeNode(stoi(token));
        t->left = unpack(ss);
        t->right = unpack(ss);
        return t;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));