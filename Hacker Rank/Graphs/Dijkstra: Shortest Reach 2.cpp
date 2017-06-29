#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector< vector< pair<int,int> > > graph(n + 1);
		for(int i = 0; i<m; i++){
			int u, v, cost;
			cin >> u >> v >> cost;
			graph[u].push_back(make_pair(cost, v));
			graph[v].push_back(make_pair(cost, u));
		}
		int root;
		cin >> root;
		vector<int> parent(n + 1);
		vector<int> distance(n + 1, 100000);
		distance[root] = 0;
		priority_queue< pair<int, int> , vector< pair<int, int> >, greater< pair<int, int> > > pq;
		pq.push(make_pair(0, root));
		while(!pq.empty()){
			int u = pq.top().second;
			int dist = pq.top().first;
			pq.pop();
			if(dist > distance[u])
				continue;
			for(int i = 0; i<graph[u].size(); i++){
				int v = graph[u][i].second;
				dist = graph[u][i].first;
				if(dist + distance[u] < distance[v]){
					distance[v] = distance[u] + dist;
					parent[v] = u;
					pq.push(make_pair(distance[v],v));
				}
			}
		}
		for(int i = 1; i<=n; i++){
			if(i == root)
				continue;
			if(distance[i] == 100000)
				cout << "-1" << " ";
			else
				cout << distance[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
