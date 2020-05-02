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

ListNode* mergeTwoList(ListNode* l1, ListNode* l2);
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* l1 = NULL;
        ListNode* l2 = NULL;
        
        if(lists.size()== 0)
            return NULL;
        
        if(lists.size() == 2)
            return mergeTwoList(lists[0], lists[1]);
            
        for(int j = 1; j< lists.size();j *=2)
        {
            for(int i = 0; i+j< lists.size()-1; i+=(j*2))
            {
                //cout<<"i:"<<i<<" j:"<<j<<endl;
                l1 = lists[i];
                l2 = lists[i+j];
                lists[i] = mergeTwoList(l1, l2); 
                l1 = lists[i]; //for [] case
            }                
        }
        //cout<<"l1:"<<l1->val<<endl;
        return mergeTwoList(l1, lists[lists.size()-1]);
    }
};


ListNode* mergeTwoList(ListNode* l1, ListNode* l2)
{
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    //cout<<"l1->val:"<<l1->val<<" l2->val:"<<l2->val<<endl;
    if(l1->val > l2->val)
    {
        l2->next = mergeTwoList(l1, l2->next);
        return l2;
    }
    else
    {
        l1->next = mergeTwoList(l1->next, l2);
        return l1;
    }
}
