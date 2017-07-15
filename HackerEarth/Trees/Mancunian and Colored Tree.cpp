#include <bits/stdc++.h>
using namespace std;

int n, c;
int parent[100005];
int color[100005];

int findanc(int x){
	int y = x;
	while(parent[y] != 0){
		y = parent[y];
		if(color[y] == color[x]){
			return y;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> c;
	parent[1] = 0;
	for(int i = 2; i <= n; i++){
		cin >> parent[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> color[i];
	}
	for(int i = 1; i <= n; i++){
		int res = findanc(i);
		if(res == 0)
			cout << -1 << " ";
		else
			cout << res << " ";
	}
	return 0;
}
