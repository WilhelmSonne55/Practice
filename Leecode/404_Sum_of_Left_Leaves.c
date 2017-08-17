/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root) {
    if(root == NULL) return 0;
    
    int sum = 0;
    struct TreeNode* l;
    struct TreeNode* r;
    
    if(root->right != NULL){    //recursion right child
        r = root->right;
        sum += sumOfLeftLeaves(r);
    }
    
    if(root->left != NULL){
        l = root->left;
            while(l->left !=NULL){  //iteration left child until the last left child
                
             if(l->right !=NULL)  //the case about the left child have right child => recursion
                  sum += sumOfLeftLeaves(l->right);
        
            l = l->left;
            } 
        
            if(l->right !=NULL){
                 sum += sumOfLeftLeaves(l->right);
             }
    }

    if(l!= NULL && l->left == NULL && l->right == NULL)
        sum += l->val;
    
        
    return sum;
}
