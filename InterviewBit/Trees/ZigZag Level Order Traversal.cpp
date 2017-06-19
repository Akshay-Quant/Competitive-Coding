/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int> > res;
    if(A == NULL)
        return res;
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    s1.push(A);
    vector<int> ans;
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            struct TreeNode* temp = s1.top();
            s1.pop();
            if(temp->right)
                s2.push(temp->right);
            if(temp->left)
                s2.push(temp->left);
            ans.push_back(temp->val);
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()>0)
            res.push_back(ans);
        ans.clear();
        while(!s2.empty()){
            struct TreeNode* temp = s2.top();
            s2.pop();
            if(temp->left)
                s1.push(temp->left);
            if(temp->right)
                s1.push(temp->right);
            ans.push_back(temp->val);
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()>0)    
            res.push_back(ans);
        ans.clear();
    }
    return res;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
