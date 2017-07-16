#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100005];
bool visited[100005] = {0};
int parent[100005] = {0};
int n, e, res;

void DFS(int root){
	visited[root] = true;
	for(int i = 0; i < graph[root].size(); i++){
		if(visited[graph[root][i]] == false){
			parent[graph[root][i]] = root;
			DFS(graph[root][i]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> e;
	for(int i = 0; i < e; i++){
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		if(visited[i] == false){
			parent[i] = -1;
			DFS(i);
		}
	}
	res = 0;
	for(int i = 1; i <= n; i++){
		if(parent[i] != -1){
			if(parent[parent[i]] == -1){
				if((graph[i].size() - 1) > graph[parent[i]].size()){
					res++;
				}
			}else{
				if(graph[i].size() > graph[parent[i]].size()){
					res++;
				}
			}
		}
	}
	cout << res << "\n";
	return 0;
}
