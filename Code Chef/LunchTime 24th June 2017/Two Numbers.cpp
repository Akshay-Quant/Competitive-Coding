#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll A,B,n;
		cin>>A>>B>>n;
		int flag = 0;
		if(n%2 == 0){
			ll temp1 = max(A,B);
			ll temp2 = min(A,B);
			ll res = temp1 / temp2;
			cout<<res<<"\n";
		}else{
			A *= 2;
			ll temp1 = max(A,B);
			ll temp2 = min(A,B);
			ll res = temp1 / temp2;
			cout<<res<<"\n";
		}
	}
	return 0;
}
