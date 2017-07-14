#include <bits/stdc++.h>
#define ll long long int
using namespace std;
double dp[1005][1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		memset(dp, 0, sizeof(dp));
		ll r, b;
		cin >> r >> b;
		cout << fixed;
		cout << setprecision(6);
		for(int i = 0; i <= r; i++){
			for(int j = 0; j <= b; j++){
				if(i == 0 || j == 0){
					dp[i][j] = 1;
				}else{
					dp[i][j] = i * 1.0 / (i + j) + (j * 1.0 / (i + j)) * ((j - 1) * 1.0 / (i + j - 1)) * dp[i][j - 2];
				}
			}
		}
		cout << dp[r][b] << "\n";
	}
	return 0;
}
