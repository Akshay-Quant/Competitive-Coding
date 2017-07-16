#include <bits/stdc++.h>
using namespace std;
int n, e, k;
vector<int> graph[100005];
bool visited[100005];

void DFS(int root){
	visited[root] = true;
	for(int i = 0; i < graph[root].size(); i++){
		if(graph[root][i] == k)
			continue;
		if(visited[graph[root][i]] == false){
			DFS(graph[root][i]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cin >> e;
	for(int i = 0; i < e; i++){
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	cin >> k;
	if(k == 0)
		DFS(1);
	else
		DFS(0);
	int count = 0;
	for(int i = 0; i <= n; i++){
		if(visited[i] == true)
			count++;
	}
	if(count == n - 1)
		cout << "Connected" << "\n";
	else
		cout << "Not Connected" << "\n";
	return 0;
}
