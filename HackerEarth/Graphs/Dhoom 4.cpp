#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[1005];
ll visited[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll key, req, n;
	cin >> key >> req;
	cin >> n;
	for(ll i = 0; i < n; i++)
		cin >> arr[i];
	memset(visited, -1, sizeof(visited));
	queue<ll> q;
	q.push(key);
	visited[key] = 0;
	while(!q.empty()){
		ll val = q.front();
		q.pop();
		if(val == req)
			break;
		for(ll i = 0; i < n; i++){
			ll tot = arr[i];
			tot = tot * val;
			tot %= 100000;
			if(visited[tot] == -1){
				visited[tot] = visited[val] + 1;
				q.push(tot);
			}
		} 
	}
	cout << visited[req] << "\n";
	return 0;
}
