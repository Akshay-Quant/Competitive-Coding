#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll a[10005];
ll dp[10005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	for(ll j = 1; j <= t; j++){
		ll n;
		cin >> n;
		for(ll i = 1; i <= n; i++){
			cin >> a[i];
		}
		dp[1] = a[1];
		dp[2] = max(a[1], a[2]);
		for(ll i = 3; i <= n; i++){
			dp[i] = max(dp[i - 2] + a[i], dp[i - 1]);
		}
		cout << "Case " << j << ": " << dp[n] << "\n";
	}
	return 0;
}
