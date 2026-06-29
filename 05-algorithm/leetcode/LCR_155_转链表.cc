/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    
    void InOrder(Node* cur, Node*& prev)
    {
        if(cur == nullptr) return ;

        InOrder(cur->left,prev);
        // 中序
        cur->left = prev;
        if(prev) prev->right = cur;

        prev = cur;

        InOrder(cur->right,prev);
    }
    
    Node* treeToDoublyList(Node* root) 
    {
        if(root == nullptr) return nullptr;

        Node* prev = nullptr;
        InOrder(root, prev);

        Node* head = root;

        while(head->left)
        {    
            head = head->left;
        }

        head->left = prev;
        prev->right = head;

        return head;
    }
};