#include <bits/stdc++.h>
using namespace std;
int dp[10005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int n = s.length();
	for(int i = n; i >= 1; i--){
		int temp = s[i - 1] - '0';
		if(temp % 2 == 0){
			dp[i] = dp[i + 1] + 1;
		}else{
			dp[i] = dp[i + 1];
		}
	}
	for(int i = 1; i <= n; i++){
		cout << dp[i] << " ";
	}
	return 0;
}
