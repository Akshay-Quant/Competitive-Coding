#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<bool> visited(100000, false);
vector<vector<ll> > graph(100000);

void DFS(ll root){
	visited[root] = true;
	for(ll i = 0; i<graph[root].size(); i++){
		if(visited[graph[root][i]] ==  false){
			DFS(graph[root][i]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	while(t--){
		for(ll i = 0; i<100000; i++){
			graph[i].clear();
		}
		ll n, m, clib, croad;
		cin >> n >> m >> clib >> croad;
		for(ll i = 0; i<m; i++){
			ll u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		if(croad >= clib){
			cout << clib * n << "\n";
		}else{
			for(ll i = 0; i<100000; i++)
				visited[i] =  false;
			ll res = 0;
			ll count = 0;
			for(ll i = 1; i<=n; i++){
				if(visited[i] == false){
					count++;
					DFS(i);
				}
			}
			res = (count * clib) + ((n - count) * croad);
			cout << res << "\n";
		}
	}
	return 0;
}
