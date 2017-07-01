void util(vector<vector<int> > &graph, stack<int> &s, int i, vector<bool> &visited){
    visited[i] = true;
    for(int j = 0; j<graph[i].size(); j++){
        if(visited[j] == false)
            util(graph, s, j, visited);
    }
    s.push(i);
}

bool DFS(int i, vector<int> &color, vector<vector<int> > &graph){
    color[i] = 1;
    for(int j = 0; j<graph[i].size(); j++){
        if(color[graph[i][j]] == 1)
            return true;
        if(color[graph[i][j]] == 0 && DFS(graph[i][j], color, graph))
            return true;
    }
    color[i] = 2;
    return false;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    stack<int> s;
    vector<vector<int> > graph(A + 1);
    for(int i = 0; i<B.size(); i++){
        graph[B[i]].push_back(C[i]);
    }
    vector<int> color(A + 1);
    for(int i = 1; i<=A; i++)
        color[i] = 0;
    for(int i = 1; i<=A; i++){
        if(color[i] == 0){
            if(DFS(i, color, graph) == true)
                return 0;
        }
    }
    return 1;
}
