/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct revListNode{
    ListNode *anspre;
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head == NULL)
            return head;
        
        int size = 1;
        ListNode* node = head; 
        vector<revListNode> vnode;
        
        while(node->next != NULL)
        {
            revListNode revList;
            revList.anspre = node;
            vnode.push_back(revList);
                        
            node = node->next;
            size++;
        }

        if(size == 1)
            return NULL;        //remove the only one
        else if(size == n)
            return head->next;  //just remove head
        
        ListNode* tmp = vnode[size-n-1].anspre; //will have error if n == size
        ListNode* tmpNext = tmp->next;
        if(tmpNext != NULL)
        {   
             tmp->next = tmpNext->next;
        }

        return head;
    }
};
