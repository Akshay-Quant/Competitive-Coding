#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, sum;
		cin >> n;
		cin >> sum;
		int val[n], wt[n];
		for(int i = 0; i < n; i++)
			cin >> val[i];
		for(int i = 0; i < n; i++)
			cin >> wt[i];
		int dp[n + 1][sum + 1];
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= sum; j++){
				if(i == 0 || j == 0)
					dp[i][j] = 0;
				else if(wt[i - 1] <= j)
					dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		cout << dp[n][sum] << "\n";
	}
	return 0;
}
