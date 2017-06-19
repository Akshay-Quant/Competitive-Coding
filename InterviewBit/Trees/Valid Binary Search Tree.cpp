/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int util(TreeNode* root,int minvalue,int maxvalue){
    if(root==NULL)
        return 1;
    if(root->val > minvalue && root->val<maxvalue &&
        util(root->left,minvalue,root->val) &&
        util(root->right,root->val,maxvalue))
        return 1;
    else
        return 0;
} 
 
int Solution::isValidBST(TreeNode* A) {
    return util(A,INT_MIN,INT_MAX);
    
}
