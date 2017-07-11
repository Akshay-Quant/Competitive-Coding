#include <bits/stdc++.h>
using namespace std;
map<int, int> s, t;
int arr[5005];
int dp[5005];
bool vis[5005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		if(s.count(arr[i]) == 0)
			s[arr[i]] = i;
		t[arr[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		int ans = dp[i - 1];
		int xortillhere = 0;
		int small = i;
		memset(vis, false, sizeof(vis));
		for(int j = i; j > 0; j--){
			int temp = arr[j];
			if(t[temp] > i)
				break;
			small = min(small, s[temp]);
			if(vis[temp] == false){
				vis[temp] = true;
				xortillhere ^= temp;
			}
			if(small == j){
				ans = max(ans, dp[j - 1] + xortillhere);
			}
		}
		dp[i] = ans;
	}
	cout << dp[n] << "\n";
	return 0;
}
