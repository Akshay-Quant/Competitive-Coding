#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int dp[100005];

int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	map <int,bool> distinct;
	for(int i = n-1; i>=0; i--){
		distinct[arr[i]] = true;
		dp[i] = distinct.size();
	}
	while(m--){
		int l;
		cin>>l;
		cout<<dp[l-1]<<"\n";
	}
	return 0;
}
