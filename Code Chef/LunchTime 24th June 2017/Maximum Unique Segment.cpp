#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll c[n + 2];
		ll w[n + 2];
		ll visited[1000005];
		memset(visited, -1, sizeof(visited));
		for(ll i = 0; i<n; i++){
			cin>>c[i];
		}
		for(ll i = 0; i<n; i++){
			cin>>w[i];
		}
		ll sum = w[0];
		ll current = 1;
		ll ans = w[0];
		visited[c[0]] = 0;
		for(ll i = 1; i<n; i++){
			ll index = visited[c[i]];
			if(index == -1 || i - current > index){
				sum += w[i];
				current++;
			}else if(i - current <= index){
				for(ll j = i - current; j<=index; j++){
					sum -= w[j];
					current--;
				}
				current++;
				sum += w[i];
			}
			if(sum > ans){
				ans = sum;
			}
			visited[c[i]] = i;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
