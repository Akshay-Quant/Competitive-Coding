#include <bits/stdc++.h>
using namespace std;
int n,m;
vector< pair<int,int> > adj[10000];
vector<bool> visited(10000,false);

int prims(int root){
	pair<int, int> p;
	priority_queue< pair<int, int> , vector< pair<int, int> >, greater< pair<int,int> > > pq;
	pq.push(make_pair(0,root));
	int mincost = 0;
	while(!pq.empty()){
		int u, cost;
		p = pq.top();
		pq.pop();
		u = p.second;
		if(visited[u] == true)
			continue;
		mincost += p.first;
		visited[u] = true;
		for(int i = 0; i<adj[u].size(); i++){
			if(visited[adj[u][i].second] == false){
				pq.push(adj[u][i]);
			}
		}
	}
	return mincost;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i<m; i++){
		int u, v, cost;
		cin >> u >> v >> cost;
		adj[u].push_back(make_pair(cost, v));
		adj[v].push_back(make_pair(cost, u));	
	}
	int root;
	cin >> root;
	cout << prims(root) << "\n";
	return 0;
}
