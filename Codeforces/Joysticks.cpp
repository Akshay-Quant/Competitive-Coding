#include <bits/stdc++.h>
using namespace std;

int dp(int a, int b){
	if(a <= 0 || b <= 0)
		return 0;
	if(a >= b)
		return 1 + dp(a - 2, b + 1);
	else
		return 1 + dp(a + 1, b - 2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b;
	cin>>a>>b;
	if(a == 1 && b == 1)
		cout<<0<<"\n";
	else{
		int res = dp(a,b);
		cout<<res<<"\n";
	}
	return 0;
}
