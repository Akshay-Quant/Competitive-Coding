int rownum[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int colnum[] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool issafe(int &x, int &y, int &N, int &M){
    if(x >= 1 && x <= N && y >= 1 && y <= M){
        return true;
    }
    return false;
}

int Solution::knight(int N, int M, int x1, int y1, int x2, int y2) {
    bool visited[N + 1][M + 1];
    for(int i = 0; i<=N; i++){
        for(int j = 0; j<=M; j++){
            visited[i][j] = false;
        }
    }
    int x, y;
    pair<int, pair<int, int> > p;
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(x1, make_pair(y1, 0)));
    while(!q.empty()){
        p = q.front();
        q.pop();
        if(visited[p.first][p.second.first] == true)
            continue;
        visited[p.first][p.second.first] = true;
        if(p.first == x2 && p.second.first == y2){
            return p.second.second;
        }
        for(int i = 0; i<8; i++){
            x = p.first + rownum[i];
            y = p.second.first + colnum[i];
            if(issafe(x, y, N, M) && visited[x][y] == false){
                q.push(make_pair(x, make_pair(y, p.second.second + 1)));
            }
        }
    }
    return -1;
}
