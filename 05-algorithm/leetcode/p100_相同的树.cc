/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) 
{
    if( p==NULL && q==NULL )
    {
        return true;
    }
    if( p==NULL || q==NULL)
    {
        return false;
    }
    
    if(p->val==q->val&&isSameTree(q->left,p->left)&&isSameTree(q->right,p->right))
    {
        return true;
    }
    
    return false;
}