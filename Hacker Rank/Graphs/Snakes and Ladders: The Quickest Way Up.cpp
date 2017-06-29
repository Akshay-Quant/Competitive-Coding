#include <bits/stdc++.h>
using namespace std;
vector<int> jump(105);
vector<bool> visited(105, false);
vector<int> dist(105);

bool valid(int root){
    if(root < 1 || root > 100 || visited[root] == true)
        return false;
    else
        return true;
}

int getres(int root){
    for(int i = 0; i<101; i++){
        visited[i] = false;
    }
    queue<int> q;
    visited[root] = true;
    dist[root] = 0;
    q.push(root);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 1; i<=6; i++){
            int next = jump[u + i];
            if(valid(next)){
                q.push(next);
                visited[next] = true;
                dist[next] = dist[u] + 1;
            }
        }
    }
    if(visited[100] == false)
        return -1;
    else
        return dist[100];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int s, l;
        cin >> s;
        for(int i = 1; i<101; i++){
            jump[i] = i;
        }
        for(int i = 0; i<s; i++){
            int u, v;
            cin >> u >> v;
            jump[u] = v;
        }
        cin >> l;
        for(int i = 0; i<l; i++){
            int u, v;
            cin >> u >> v;
            jump[u] = v;
        }
        cout << getres(1) << "\n";
    }
    return 0;
}
