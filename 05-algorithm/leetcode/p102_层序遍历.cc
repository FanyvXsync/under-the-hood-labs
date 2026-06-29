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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> vv;
        if(root == nullptr) return vv;

        queue<TreeNode*> q;
        int levelSize = 0;
        q.push(root);
        levelSize = 1;

        while(levelSize)
        {
            vector<int> v;
            
            while(levelSize--)
            {
               
                TreeNode* tmp = q.front(); q.pop();
                v.push_back(tmp->val);

                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }

            levelSize = q.size();
            vv.push_back(v);

        }
        
        return vv;
        
    }
};