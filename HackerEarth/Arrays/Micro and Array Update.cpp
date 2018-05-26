#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		int min = INT_MAX;
		for(int i = 0;i < n;i++){
			if(arr[i] < min)
				min = arr[i];
		}
		int res = k - min;
	    if(res>0)cout << res << endl;
	    else cout << 0 << endl;
	}
	return 0;
}
