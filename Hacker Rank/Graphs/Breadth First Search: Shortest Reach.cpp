#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	while(q--){
		int n,m;
		cin >> n >> m;
		vector< vector < pair<int,int> > > graph(n + 1);
		for(int i = 0; i<m; i++){
			int u,v;
			cin >> u >> v;
			graph[u].push_back(make_pair(6, v));
			graph[v].push_back(make_pair(6, u));
		}
		int root;
		cin >> root;
		vector<int> parent(n + 1);
		vector<int> distance(n + 1, INT_MAX);
		vector<bool> visited(n + 1, false);
		distance[root] = 0;
		priority_queue< pair<int,int>, vector <pair<int,int> >, greater< pair<int, int> > > pq;
		pq.push(make_pair(0,root));
		while(!pq.empty()){
			int u = pq.top().second;
			int dist = pq.top().first;
			pq.pop();
			if(dist > distance[u])
				continue;
			for(int i = 0; i<graph[u].size(); i++){
				int v = graph[u][i].second;
				dist = graph[u][i].first;
				if(distance[v] > distance[u] + dist){
					distance[v] = distance[u] + dist;
					parent[v] = u;
					pq.push(make_pair(distance[v],v));
				}
			}
		}
		for(int i = 1; i<=n; i++){
			if(i == root)
				continue;
			if(distance[i] == INT_MAX)
				cout<<"-1"<<" ";
			else
				cout<<distance[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
