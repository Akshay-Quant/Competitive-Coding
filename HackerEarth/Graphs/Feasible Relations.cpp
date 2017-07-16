#include <bits/stdc++.h>
using namespace std;
vector<int> graph[1000005];
bool visited[1000005];
int parent[1000005];
int t, n, m, flag;
vector< pair< int, int > > unequal;

void DFS(int root, int level){
	parent[root] = level;
	visited[root] = true;
	for(int i = 0; i < graph[root].size(); i++){
		if(visited[graph[root][i]] == false){
			DFS(graph[root][i], level);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while(t--){
		flag = 0;
		for(int i = 0; i < 1000005; i++){
			graph[i].clear();
		}
		memset(visited, false, sizeof(visited));
		memset(parent, 0, sizeof(parent));
		unequal.clear();
		cin >> n >> m;
		for(int i = 0; i < m; i++){
			int x, y;
			string s;
			cin >> x >> s >> y;
			if(s == "="){
				graph[x].push_back(y);
				graph[y].push_back(x);
			}else{
				unequal.push_back(make_pair(x, y));
			}
		}
		for(int i = 1; i <= n; i++){
			if(visited[i] == false){
				DFS(i, i);
			}
		}
		for(int i = 0; i < unequal.size(); i++){
			int t1 = unequal[i].first;
			int t2 = unequal[i].second;
			if(parent[t1] == parent[t2]){
				flag = 1;
				break;
			}
		}
		if(flag == 1){
			cout << "NO" << "\n";
		}else{
			cout << "YES" << "\n";
		}
	}
	return 0;
}
