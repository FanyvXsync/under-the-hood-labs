/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    string tree2str(TreeNode* root) 
    {
        string ret;

        if(root == nullptr)
            return ret;
        
        ret += to_string(root->val);

        
        if(root->left|| root->right)
        {
            ret += "(";
            ret += tree2str(root->left);
            ret += ")";
        }

        if(root->right)
        {
            ret += "(";
            ret += tree2str(root->right);
            ret += ")";
        }

        return ret;
    }
};