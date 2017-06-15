#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,ll> m;

int main(){
	int n;
	cin>>n;
	ll arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		m[arr[i]]++;
	}
	sort(arr,arr+n);
	ll count=0;
	if(m[arr[0]]>2){
		count=(m[arr[0]])*(m[arr[0]]-1)*(m[arr[0]]-2)/6;
		cout<<count<<endl;
	}else if(m[arr[0]]==2){
		count=m[arr[2]];
		cout<<count<<endl;
	}else{
		if(m[arr[1]]==1){
			count=m[arr[2]];
			cout<<count<<endl;
		}else{
			count=m[arr[1]]*(m[arr[1]]-1)/2;
			cout<<count<<endl;
		}
	}
	return 0;
}
