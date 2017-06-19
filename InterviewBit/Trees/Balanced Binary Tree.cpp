/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int height(TreeNode* root){
    if(root==NULL)
        return 0;
    else{
        int left=height(root->left);
        int right=height(root->right);
        return 1+max(left,right);
    }
} 
 
int Solution::isBalanced(TreeNode* A) {
    if(A==NULL)
        return 1;
    int left=height(A->left);
    int right=height(A->right);
    if(abs(left-right)<=1 && isBalanced(A->left) && isBalanced(A->right)){
        return 1;
    }
    return 0;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
