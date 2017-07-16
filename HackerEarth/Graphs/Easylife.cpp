#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100005];
bool visited[100005];
bool final[100005];
int n, e;
double res, temp;

void DFS(int root){
	visited[root] = true;
	temp++;
	res += graph[root].size();
	for(int i = 0; i < graph[root].size(); i++){
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
	double ans = INT_MIN;
	double tot1, tot2;
	for(int i = 1; i <= n; i++){
		res = 0;
		temp = 0;
		if(visited[i] == false){
			DFS(i);
			int a = res;
			a /= 2;
			res = a;
			if(ans < (res / temp)){
				ans = res / temp;
				tot1 = res;
				tot2 = temp;
			}
		}
	}
	if(ans > 1){
		cout << ">1" << "\n";
	}else{
		if(tot1 == tot2){
			tot1 = 1;
			tot2 = 1;
		}
		cout << tot1 << "/" << tot2 << "\n";
	}
	return 0;
}
