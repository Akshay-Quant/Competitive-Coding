#include <bits/stdc++.h>
using namespace std;

int cuts(vector<vector<int> > adj, int root){
	queue<int> bfs;
	bfs.push(root);
	int n = adj.size();
	vector<bool> visited(n, false);
	visited[root] = true;
	while(!bfs.empty()){
		int temp = bfs.front();
		bfs.pop();
		for(int i = 0; i<n; i++){
			if(adj[temp][i] == 1){
				if(visited[i] == false){
					visited[i] = true;
					bfs.push(i);
				}
			}
		}
	}
	int count = 0;
	for(int i = 0; i<n; i++){
		if(visited[i] == 1)
			count++;
	}
	return count;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	vector<vector<int> > adj(n, vector<int> (n,0));
	vector<pair<int,int> > edges;
	int u, v;
	for(int i = 0; i<m; i++){
		cin>>u>>v;
		adj[u - 1][v - 1] = 1;
		adj[v - 1][u - 1] = 1;
		edges.push_back(make_pair(u - 1,v - 1));
	}
	int count = 0;
	for(int i = 0; i<m; i++){
		u = edges[i].first;
		v = edges[i].second;
		adj[u][v] = 0;
		adj[v][u] = 0;
		if(cuts(adj, u) % 2 == 0)
			count++;
		else
			adj[u][v] = 1;
			adj[v][u] = 1;
	}
	cout<<count<<"\n";
	return 0;
}
