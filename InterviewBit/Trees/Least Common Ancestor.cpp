/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* util(TreeNode* A, int val1, int val2){
    if(A == NULL || A->val == val1 || A->val == val2)
        return A;
    TreeNode* Aleft = util(A->left, val1, val2);
    TreeNode* Aright = util(A->right, val1, val2);
    if(Aleft && Aright)
        return A;
    if(Aleft)
        return Aleft;
    else 
        return Aright;
}

bool find(TreeNode* A, int value){
    if(A == NULL)
        return false;
    if(A->val == value)
        return true;
    if((A->left && find(A->left,value)) || ((A->right) && find(A->right,value)))
        return true;
    return false;
    
}
 
int Solution::lca(TreeNode* A, int val1, int val2) {
    if(!find(A,val1) || !find(A,val2))
        return -1;
    TreeNode* temp = util(A, val1, val2);
    if(temp!=NULL)
        return temp->val;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
