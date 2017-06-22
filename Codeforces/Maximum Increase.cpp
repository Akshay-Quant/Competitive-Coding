#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[100005];

int main(){
  ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	ll current = 0;
	ll maxi = 0;
	for(int i = 1; i<n; i++){
		if(arr[i] > arr[i-1]){
			current++;
			maxi = max(current,maxi);
		}else{
			current = 0;
		}
	}
	cout<<maxi + 1<<"\n";
	return 0;
}
