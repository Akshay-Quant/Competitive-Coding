/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* build(ListNode* start, ListNode* end){
    if(start == end)
        return NULL;
    ListNode* slow = start;
    ListNode* fast = start;
    while(fast != end && fast->next != end){
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode* root = new TreeNode(slow->val);
    root->left = build(start,slow);
    root->right = build(slow->next, end);
    return root;
} 
 
TreeNode* Solution::sortedListToBST(ListNode* A) {
    return build(A, NULL);
}
