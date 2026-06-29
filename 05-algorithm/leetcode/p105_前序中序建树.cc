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
    TreeNode* Build(vector<int>& preorder, vector<int>& inorder, int& previ, int begini, int endi)
    {
        if(begini > endi) return nullptr;

        TreeNode* root = new TreeNode((preorder[previ]));

        int rooti = begini;
        while(rooti <= endi && inorder[rooti] != preorder[previ])
        {
            rooti++;
        }
        previ++;

        // [begini , rooti - 1] rooti [rooti + 1, endi];
        root->left = Build(preorder, inorder, previ, begini, rooti - 1);
        root->right = Build(preorder, inorder, previ, rooti + 1, endi);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int previ = 0;
        int n = preorder.size();
        return Build(preorder, inorder, previ, 0, n-1);
    }
};