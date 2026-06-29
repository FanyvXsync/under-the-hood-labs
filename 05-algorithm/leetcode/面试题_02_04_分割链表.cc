/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        if(head==NULL)
        {
            return head;
        }



        ListNode * lesshead=(ListNode * )malloc(sizeof(ListNode));
        ListNode* greaterhead=(ListNode *)malloc(sizeof(ListNode));

        ListNode * lesstail=lesshead;
        ListNode * greatertail=greaterhead;

        


        ListNode * pcur=head;

        while(pcur)
        {
            if(pcur->val < x)
            {
                lesstail->next=pcur;
                lesstail=pcur;

            }
            else
            {
                greatertail->next=pcur;
                greatertail=pcur;
            }


            pcur=pcur->next;

        }

        greatertail->next=NULL;
        lesstail->next=greaterhead->next;

        
        ListNode * tmp=lesshead->next;

        free(lesshead);
        lesshead=NULL;

        free(greaterhead);
        greaterhead=NULL;
        
        return tmp;





        
    }
};