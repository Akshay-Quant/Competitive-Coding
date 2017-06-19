/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int mirrorimage(TreeNode* A, TreeNode* B){
    if(A==NULL && B==NULL)
        return 1;
    if(A!=NULL && B!=NULL && A->val==B->val && 
        mirrorimage(A->left,B->right) && 
        mirrorimage(A->right,B->left))
        return 1;
    return 0;
} 
 
int Solution::isSymmetric(TreeNode* A) {
    if(mirrorimage(A,A)){
        return 1;
    }
    return 0;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
