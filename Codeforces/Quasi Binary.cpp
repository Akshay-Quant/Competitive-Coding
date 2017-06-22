#include <bits/stdc++.h>
using namespace std;
int dp[1000005];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int temp = 1;
	int maxi = 0;
	while(n>0){
		int rem = n%10;
		maxi = max(maxi,rem);
		for(int i = 0; i<rem; i++){
			dp[i] += temp;
		}
		temp = temp * 10;
		n = n / 10;
	}
	cout<<maxi<<"\n";
	for(int i = 0; i<maxi; i++)
		cout<<dp[i]<<" ";
	cout<<"\n";
	return 0;
}
