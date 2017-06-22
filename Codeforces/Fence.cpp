#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[150005];
ll dp[150005];

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin>>n>>k;
	ll prev = 0;
	for(int i = 0; i<n; i++){
		cin>>arr[i];
		prev +=  arr[i];
		dp[i] = prev;
	}
	ll currentmin = dp[k-1];
	ll index = 0;
	for(int i = 0; i < n - k; i++){
		prev = dp[i + k] - dp[i];
		if(prev < currentmin){
			currentmin = prev;
			index = i + 1;
		}
	}
	cout<<index+1<<"\n";
	return 0;
}
