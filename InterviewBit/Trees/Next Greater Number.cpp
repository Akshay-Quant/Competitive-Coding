/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Find(struct TreeNode* root,int B){
    if(root==NULL)
        return NULL;
    if(root->val==B)
        return root;
    else if(root->val < B){
        return Find(root->right,B);
    }else{
        return Find(root->left,B);
    }
}

TreeNode* Findleft(struct TreeNode* root){
    if(root==NULL)
        return NULL;
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
 
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    TreeNode* current = Find(A,B);
    if(current == NULL)
        return NULL;
    if(current->right != NULL){
        return Findleft(current->right);
    }else{
        TreeNode* successor = NULL;
        TreeNode* ancestor = A;
        while(ancestor!=current){
            if(current->val < ancestor->val){
                successor = ancestor;
                ancestor = ancestor->left;
            }else{
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}
