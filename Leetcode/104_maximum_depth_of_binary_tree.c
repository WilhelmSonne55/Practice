/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root) {
    int ls =0, rs=0;
    if(!root)
        return 0;
    
        if(root->right !=NULL){
            rs +=maxDepth(root->right);
        }
        
        if(root->left !=NULL){
            ls +=maxDepth(root->left);
        } 
    
    if(rs<ls)
        return ++ls;
    else
        return ++rs;
}
