#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;

ll dprecurr(ll n){
	ll fib[2][2] = {{1, 1}, {1, 0}};
	ll ret[2][2] = {{1, 1}, {0, 1}};
	ll temp[2][2] = {{0, 0}, {0, 0}};
	int i, j, k;
	while(n){
		if(n & 1){
			memset(temp, 0, sizeof(temp));
			for(int i = 0; i < 2; i++){
				for(int j = 0; j < 2; j++){
					for(int k = 0; k < 2; k++){
						temp[i][j] = (temp[i][j] + (ret[i][k] * fib[k][j])) % MOD;
					}
				}
			}
			for(int i = 0; i < 2; i++){
				for(int j = 0; j < 2; j++){
					ret[i][j] = temp[i][j];
				}
			}
		}
		memset(temp, 0, sizeof(temp));
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				for(int k = 0; k < 2; k++){
					temp[i][j] = (temp[i][j] + (fib[i][k] * fib[k][j])) % MOD;
				}
			}
		}
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				fib[i][j] = temp[i][j];
			}
		}
		n /= 2;
	}
	return ret[0][1] % MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		cout << dprecurr(n + 1) << "\n";
	}
	return 0;
}
