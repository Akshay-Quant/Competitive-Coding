#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[200005];

int main(){
	string s;
	cin>>s;
	ll q;
	cin>>q;
	dp[0]=0;
	for(int i=1;i<s.length();i++){
		if(s[i]==s[i-1]){
			dp[i]=dp[i-1]+1;
		}else{
			dp[i]=dp[i-1];
		}
	}
	while(q--){
		ll l,r;
		cin>>l>>r;
		cout<<dp[r-1]-dp[l-1]<<endl;
	}
	return 0;
}
