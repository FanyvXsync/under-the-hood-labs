/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool Creat_Road(TreeNode* root, stack<TreeNode*>& st, TreeNode* p)
    {
        if(root == nullptr) return false;

        st.push(root);
        if(root == p) return true;
        
        if(Creat_Road(root->left, st, p)) return true;
        if(Creat_Road(root->right, st, p)) return true;
        st.pop();
        return false;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;

        Creat_Road(root,st1,p);
        Creat_Road(root,st2,q);

        while(st1.size() > st2.size()) st1.pop(); 
        while(st2.size() > st1.size()) st2.pop();

        while(st1.top() != st2.top())
        {
            st1.pop();
            st2.pop();
        }

        return st1.top(); 

    }
};