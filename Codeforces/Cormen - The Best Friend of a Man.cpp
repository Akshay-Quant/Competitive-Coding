#include <bits/stdc++.h>
using namespace std;
int dp[505];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		cin>>dp[i];
	}
	int count=0;
	for(int i = 1;i<n;i++){
		if(dp[i] + dp[i-1] < k){
			count += (k-dp[i]-dp[i-1]);
			dp[i] = dp[i] + (k-dp[i]-dp[i-1]);
		}
	}
	cout<<count<<"\n";
	for(int i = 0;i<n;i++){
		cout<<dp[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
