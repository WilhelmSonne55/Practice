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

struct compare{
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        ListNode ans = ListNode(0);
        
        if(lists.size() == 0)
            return NULL;
        
        for(auto l: lists)
        {
            //cout<<"l:"<<l->val<<endl;
            if(l != NULL)
                q.push(l);
        }
        ListNode* node = &ans;
        while(!q.empty())
        {
            //cout<<"q.top:"<<q.top()->val<<endl;
            node->next = q.top();
            q.pop();
            node = node->next;
            if(node->next)
                q.push(node->next);
        }
        
        return ans.next;
    }
};
