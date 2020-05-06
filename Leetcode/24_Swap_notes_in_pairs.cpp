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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL)
            return head;
        
        ListNode* pre = head;
        ListNode* node = pre->next;
        
        if(node == NULL)
            return pre;
        
        ListNode* tmp = node->next;

        node->next = pre;
        pre->next = swapPairs(tmp);
        
        return node;
    }
};
