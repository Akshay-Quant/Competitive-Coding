/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    map<int,int> m;
    for(int i=0;i<A.size();i++){
        ListNode* temp=A[i];
        while(temp!=NULL){
            int value=temp->val;
            if(m.find(value)!=m.end()){
                m[value]++;
            }else{
                m[value]=1;
            }
            temp=temp->next;
        }
    }
    ListNode* head=NULL;
    ListNode* current=NULL;
    auto index=m.begin();
    while(index!=m.end()){
        while(index->second>0){
            ListNode* temp=new ListNode(index->first);
            if(head==NULL){
                head=temp;
                current=temp;
            }else{
                current->next=temp;
                current=current->next;
            }
            index->second--;
        }
        index++;
    }
    return head;
}
