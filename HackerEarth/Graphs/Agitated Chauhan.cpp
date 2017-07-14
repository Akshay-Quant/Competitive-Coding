#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector< vector <pair <int, int> > > graph(n + 1);
		for(int i = 0; i < n- 1; i++){
			int x, y, w;
			cin >> x >> y >> w;
			graph[x].push_back(make_pair(y, w));
			graph[y].push_back(make_pair(x, w));
		}
		queue<int> q;
		q.push(1);
		bool visited[n + 1];
		int level[n + 1];
		memset(visited, false, sizeof(visited));
		memset(level, 0, sizeof(level));
		int path = 0;
		int res = 0;
		visited[1] = true;
		while(!q.empty()){
			int x = q.front();
			q.pop();
			for(int i = 0; i < graph[x].size(); i++){
				int y = graph[x][i].first;
				int w = graph[x][i].second;
				if(visited[y] == false){
					visited[y] = true;
					q.push(y);
					level[y] = level[x] + w;
					if(path < level[y]){
						path = level[y];
						res = y;
					}
				}
			}
		}
		memset(visited, false, sizeof(visited));
		memset(level, 0, sizeof(level));
		q.push(res);
		path = 0;
		visited[res] = true;
		while(!q.empty()){
			int x = q.front();
			q.pop();
			for(int i = 0; i < graph[x].size(); i++){
				int y = graph[x][i].first;
				int w = graph[x][i].second;
				if(visited[y] == false){
					visited[y] = true;
					q.push(y);
					level[y] = level[x] + w;
					if(path < level[y]){
						path = level[y];
						res = y;
					}
				}
			}
		}
		int cost = 0;
		if(path > 100)
			cost = 100;
		if(path > 1000)
			cost = 1000;
		if(path > 10000)
			cost = 10000;
		cout << cost << " " << path << "\n";
	}
	return 0;
}
