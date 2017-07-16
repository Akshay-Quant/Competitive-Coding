#include <bits/stdc++.h>
using namespace std;
int n, e, tot1, tot2;
vector<int> graph[100005];
int in[100005] = {0};
int out[100005] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	tot1 = tot2 = 0;
	cin >> n >> e;
	for(int i = 0; i < e; i++){
		int x, y;
		cin >> x >> y;
		out[x]++;
		in[y]++;
		graph[x].push_back(y);
	}
	for(int i = 1; i <= n; i++){
		if(out[i] == 0){
			tot1++;
		}
	}
	for(int i = 1; i <= n; i++){
		if(in[i] == 0){
			tot2++;
		}
	}
	cout << max(tot1, tot2) << "\n";
	return 0;
}
