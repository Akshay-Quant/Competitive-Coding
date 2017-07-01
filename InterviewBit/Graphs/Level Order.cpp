/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int> > res;
    vector<int> temp;
    queue<TreeNode* > q;
    queue<int> level;
    if(A == NULL)
        return res;
    q.push(A);
    level.push(0);
    while(!q.empty()){
        TreeNode* current = q.front();
        int l = level.front();
        if(res.size() != l + 1){
            res.push_back(temp);
        }
        res[l].push_back(current->val);
        if(current->left != NULL){
            q.push(current->left);
            level.push(l + 1);
        }
        if(current->right != NULL){
            q.push(current->right);
            level.push(l + 1);
        }
        q.pop();
        level.pop();
    }
    return res;
}   
