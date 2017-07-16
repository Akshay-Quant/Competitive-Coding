#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100005];
bool visited[100005] = {false};
int n, e, count1 = 0;

void DFS(int root){
	visited[root] = true;
	for(int i = 0; i < graph[root].size(); i++){
		count1++;
		if(visited[graph[root][i]] == false){
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
	int res = INT_MIN;
	for(int i = 1; i <= n; i++){
		if(visited[i] == false){
			count1 = 0;
			DFS(i);
			res = max(res, count1 / 2);
		}
	}
	cout << res << "\n";
	return 0;
}
