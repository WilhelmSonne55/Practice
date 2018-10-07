/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *next_l1 = l1;
            ListNode *next_l2 = l2;
            ListNode *ans;
            ListNode *tmp;
            int next_val = 0;
        
            int val =  (next_l1->val + next_l2->val + next_val);
            int digit_val = val%10;
            next_val = val/10;
        
            ans = new ListNode(digit_val);
            tmp = ans;
            next_l1 = next_l1->next;
            next_l2 = next_l2->next;
        
        while(1)
        {
        
            if(next_l1 != NULL && next_l2 != NULL)
            {
                val =  (next_l1->val + next_l2->val + next_val);
                digit_val = val%10;
                next_val = val/10;
                ListNode *tmp2 = new ListNode(digit_val);
                tmp->next = tmp2;
                tmp = tmp->next;
                next_l1 = next_l1->next;
                next_l2 = next_l2->next;
            }
            else if(next_l1 != NULL && next_l2 ==NULL)
            {
                val =  (next_l1->val + next_val);
                digit_val = val%10;
                next_val = val/10;
                ListNode *tmp2 = new ListNode(digit_val);
                tmp->next = tmp2;
                tmp = tmp->next;
                next_l1 = next_l1->next;
            }
            else if(next_l1 == NULL && next_l2 !=NULL)
            {
                val =  ( next_l2->val + next_val);
                digit_val = val%10;
                next_val = val/10;
                ListNode *tmp2 = new ListNode(digit_val);
                tmp->next = tmp2;
                tmp = tmp->next;
                next_l2 = next_l2->next;            
            }
            else
            {
                if(next_val  == 1)
                {
                    ListNode *tmp2 = new ListNode(next_val);
                    tmp->next = tmp2;
                    tmp = tmp->next;
                }
                
                break;
            }
        }
        return ans;
    }
};
