#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll t, n, handshakes, root, tot;
vector<ll> adj[100005];
ll level[100005];

void DFS(ll root, ll height){
	level[root] = height;
	for(ll i = 0; i < adj[root].size(); i++){
		DFS(adj[root][i], height + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while(t--){
		cin >> n;
		for(ll i = 1; i <= n; i++){
			adj[i].clear();
		}
		for(ll i = 1; i <= n; i++){
			ll x;
			cin >> x;
			if(x == 0){
				root = i;
			}else{
				adj[x].push_back(i);
			}
		}
		DFS(root, 0);
		handshakes = 0;
		for(ll i = 1; i <= n; i++){
			handshakes += level[i];
		}
		tot = (n * (n - 1)) / 2;
		cout << handshakes << " " << tot - handshakes << "\n";
	}
	return 0;
}
