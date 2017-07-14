#include <bits/stdc++.h>
using namespace std;

int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m, tot, res, nodes;
int graph[1005][1005];
bool visited[1005][1005];

bool issafe(int i, int j){
	if((i >= 0) && (i < n) && (j >= 0) && (j < m) && (graph[i][j] == 1) && (!visited[i][j]))
		return true;
	return false;
}

void DFS(int i, int j){
	visited[i][j] = true;
	nodes++;
	for(int k = 0; k < 8; k++){
		if(issafe(i + row[k], j + col[k])){
			DFS(i + row[k], j + col[k]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		tot = 0, res = 0;
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> graph[i][j];
			}
		}
		memset(visited, false, sizeof(visited));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(graph[i][j] == 1 && visited[i][j] == false){
					nodes = 0;
					DFS(i, j);
					if(nodes > res)
						res = nodes;
					tot++;
				}
			}
		}
		cout << tot << " " << res << "\n";
	}
	return 0;
}
