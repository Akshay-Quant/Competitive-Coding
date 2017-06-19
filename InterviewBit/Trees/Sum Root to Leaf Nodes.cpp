/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int getsum(TreeNode* A, int sum, int ans){
    if(A == NULL)
        return 0;
    sum = (((sum)%1003*10)%1003 + (A->val)%1003)%1003;
    if(A->left == NULL && A->right == NULL)
        return sum%1003;
    return (getsum(A->left, sum, ans)%1003 + getsum(A->right, sum, ans)%1003)%1003;
} 
 
int Solution::sumNumbers(TreeNode* A) {
    int ans = getsum(A, 0, 0);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
