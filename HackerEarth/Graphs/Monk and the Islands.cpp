#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;
		vector < vector <ll> > graph(n + 1);
		for(ll i = 0; i < m; i++){
			ll x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		queue< pair <ll, ll> > q;
		q.push(make_pair(0, 1));
		bool visited[n + 1];
		for(ll i = 0; i < n + 1; i++){
			visited[i] = false;
		}
		visited[1] = true;
		int flag = 0;
		while(!q.empty()){
			pair<ll, ll> temp = q.front();
			q.pop();
			for(int i = 0; i < graph[temp.second].size(); i++){
				if(graph[temp.second][i] == n){
					cout << temp.first + 1 << "\n";
					flag = 1;
					break;
				}
				if(visited[graph[temp.second][i]] == false){
					visited[graph[temp.second][i]] = true;
					q.push(make_pair(temp.first + 1, graph[temp.second][i]));
				}
			}
			if(flag)
				break;
		}
		if(flag == 0)
			cout << -1 << "\n";
	}
	return 0;
}
