string Solution::multiple(int A) {
    vector<int> visited(A,0), parent(A,0), value(A,0);
    string res = "";
    queue<int> bfs;
    int temp = 1 % A;
    visited[temp] = 1;
    value[temp] = 1;
    bfs.push(temp);
    while(1){
        temp = bfs.front();
        bfs.pop();
        int a = temp;
        if(a == 0){
            res += (char)(value[a] + '0');
            a = parent[a];
            while(a != 0){
                res += (char)(value[a] + '0');
                a = parent[a];
            }
            reverse(res.begin(), res.end());
            return res;
        }
        int b = (a * 10) % A;
        if(visited[b] == 0){
            visited[b] = 1;
            bfs.push(b);
            parent[b] = a;
            value[b] = 0;
        }
        b++;
        if(b >= A)
            b -= A;
        if(visited[b] == 0){
            visited[b] = 1;
            bfs.push(b);
            parent[b] = a;
            value[b] = 1;
        }
    }
}
