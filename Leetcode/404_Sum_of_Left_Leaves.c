/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root) {
    int sum=0;
    struct TreeNode* tmp = root;
    struct TreeNode* left;
    struct TreeNode* right;
    
    if(tmp==NULL)
        return 0;
    
    if(tmp->right !=NULL){          //recursive right childe
        right = tmp->right;
        sum += sumOfLeftLeaves(right);
    }
    
    if(tmp->left !=NULL){
        left =tmp->left;
        struct TreeNode* prev;     //recorde the previous left childe for left!=NULL
        while(left!=NULL){         //using left!=NULL instead of left->left!=NULL for not missing left->right !=NULL
            if(left->right !=NULL)  
                sum+=sumOfLeftLeaves(left->right);
            prev = left;
            left = left->left;
        }
        if(prev->right==NULL)
            sum +=prev->val;   
    }

    return sum;
}
