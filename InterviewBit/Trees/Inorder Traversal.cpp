/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> res;
    stack<TreeNode*> s;
    bool flag=0;
    while(!flag){
        if(A!=NULL){
            s.push(A);
            A = A->left;
        }else{
            if(!s.empty()){
                TreeNode* temp=s.top();
                res.push_back(temp->val);
                s.pop();
                A=temp->right;
            }else{
                flag=1;
            }
        }
    }
    return res;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
