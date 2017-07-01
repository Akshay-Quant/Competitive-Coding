int parent[1005];
int rnk[1005];
bool visited[1005];

int findparent(int a){
    if(parent[a] == a)
        return a;
    return parent[a] = findparent(parent[a]);
}

void unionset(int a, int b){
    int parentA = findparent(a);
    int parentB = findparent(b);
    if(parentA == parentB)
        return;
    if(rnk[parentA] < rnk[parentB])
        parent[parentB] = parentA;
    else if(rnk[parentA] > rnk[parentB])
        parent[parentA] = parentB;
    else{
        rnk[parentA]++;
        parent[parentB] = parentA;
    }
}

bool findblock(int a, int A, int B, int C, int D, vector<pair<int, pair<int,int> > > graph){
    int top = 0;
    int bottom = INT_MAX;
    int left = INT_MAX;
    int right = 0;
    for(int i = 0; i<C; i++){
        if(parent[graph[i].first] == a){
            int x = graph[i].second.first;
            int y = graph[i].second.second;
            top = max(top, y + D);
            bottom = min(bottom, y - D);
            left = min(left, x - D);
            right = max(right, x + D);
        }
    }
    if(top >= B && bottom <= 0)
        return true;
    if(right >= A && left <= 0)
        return true;
    if(top >= B && right >=A)
        return true;
    if(left <= 0 && bottom <= 0)
        return true;
    return false;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<pair<int,pair<int,int> > > graph;
    int id = 0;
    for(int i = 0; i<C; i++){
        graph.push_back(make_pair(id, make_pair(E[i],F[i])));
        id++;
    }
    for(int i = 0; i<=1000; i++){
        parent[i] = i;
        rnk[i] = 1;
        visited[i] = false;
    }
    for(int i = 0; i<C; i++){
        for(int j = i; j<C; j++){
            if(i == j)
                continue;
            int x1 = graph[i].second.first;
            int x2 = graph[j].second.first;
            int y1 = graph[i].second.second;
            int y2 = graph[j].second.second;
            if(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)) <= (4*D*D)){
                unionset(graph[i].first, graph[j].first);
            }
        }
    }
    for(int i = 0; i<C; i++){
        if(!visited[parent[graph[i].first]]){
            visited[parent[graph[i].first]] = true;
            bool flag = findblock(parent[graph[i].first], A, B, C, D, graph);
            if(flag)
                return "NO";
        }
    }
    return "YES";
}
