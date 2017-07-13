#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000009
using namespace std;
ll dp[10000005] = {0};

int main(){
	ll t;
	cin >> t;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 10;
	dp[3] = 25;
	for(ll i = 4; i < 10000001; i++){
		ll x = (i * i) % MOD;
		dp[i] = dp[i - 2] + (4 * x) - (6 * (i - 1));
		dp[i] %= MOD;
		if(dp[i] < 0)
			dp[i] += MOD;
	}
	while(t--){
		ll n;
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}
