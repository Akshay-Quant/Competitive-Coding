#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll x1,y1,x2,y2,x,y;
	cin>>x1>>y1>>x2>>y2;
	cin>>x>>y;
	x2=x2-x1;
	y2=y2-y1;
	if(x2%x!=0 || y2%y!=0){
		cout<<"NO"<<endl;
		return 0;
	}
	ll m=y2/y;
	if(m%2==1){
		x2=x2-x;
	}
	ll n=x2/x;
	if(n%2==0){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}
