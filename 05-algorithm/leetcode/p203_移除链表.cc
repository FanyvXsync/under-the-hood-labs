/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode listnode ;

struct ListNode* removeElements(struct ListNode* head, int val) 
{
    listnode * newhead=(listnode*)malloc(sizeof(listnode));
    listnode * newtail=newhead;
    listnode * cur = head;

    while (cur)
    {
        if(cur->val!=val)
        {
            newtail->next=cur;
            newtail=cur;
        }
        cur=cur->next;

    }

    newtail->next=NULL;

    

    return newhead->next;


    
    
}