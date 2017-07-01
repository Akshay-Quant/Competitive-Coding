/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    map< UndirectedGraphNode*, UndirectedGraphNode* > m;
    queue<UndirectedGraphNode* > q;
    q.push(node);
    UndirectedGraphNode* root = new UndirectedGraphNode(node -> label);
    m[node] = root;
    while(!q.empty()){
        UndirectedGraphNode *temp = q.front();
        q.pop();
        vector<UndirectedGraphNode* > v = temp -> neighbors;
        for(int i = 0; i<v.size(); i++){
            if(m[v[i]] == NULL){
                UndirectedGraphNode* temp2 = new UndirectedGraphNode(v[i] -> label);
                q.push(v[i]);
                m[v[i]] = temp2;
            }
            m[temp] -> neighbors.push_back(m[v[i]]);
        }
    }
    return m[node];
}
