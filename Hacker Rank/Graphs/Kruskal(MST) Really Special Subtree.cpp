#include <bits/stdc++.h>
using namespace std;
vector<int> parent(10000);
vector<int> rnk(10000);
int n, m;

int root(int u){
	while(parent[u] != u)
		u = parent[u];
	return u;
}

void unionset(int u, int v){
	int parentu = root(u);
	int parentv = root(v);
	if(rnk[parentu] > rnk[parentv])
		parent[parentv] = parentu;
	else
		parent[parentu] = parentv;
	if(rnk[parentu] == rnk[parentv])
		rnk[parentv]++;
}

int kruskal(vector<pair<int, pair<int,int> > > edges){
	int u, v;
	int mincost = 0;
	int cost = 0;
	for(int i = 0; i<m; i++){
		u = edges[i].second.first;
		v = edges[i].second.second;
		cost = edges[i].first;
		if(root(u) != root(v)){
			mincost += cost;
			unionset(u,v);
		}
	}
	return mincost;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 0; i<10000; i++){
		parent[i] = i;
		rnk[i] = 0;
	}
	cin >> n >> m;
	vector<vector<int> > adj(n);
	vector<pair< int, pair<int,int> > > edges;
	for(int i = 0; i<m; i++){
		int u, v, weight;
		cin >> u >> v >> weight;
		edges.push_back(make_pair(weight, make_pair(u - 1, v - 1)));
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}
	sort(edges.begin(), edges.end());
	cout<<kruskal(edges)<<"\n";
	return 0;
}
