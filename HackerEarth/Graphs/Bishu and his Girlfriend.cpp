#include <bits/stdc++.h>
using namespace std;
vector<int> graph[1005];
int visited[1005] = {0};
int n, q;

void DFS(int root, int level){
	visited[root] = level;
	for(int i = 0; i < graph[root].size(); i++){
		if(visited[graph[root][i]] == 0){
			DFS(graph[root][i], level + 1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	cin >> q;
	DFS(1, 1);
	int mini = 0, minindex = INT_MAX;
	while(q--){
		int x;
		cin >> x;
		if(minindex > visited[x]){
			minindex = visited[x];
			mini = x;
		}
	}
	cout << mini << "\n";
	return 0;
}
