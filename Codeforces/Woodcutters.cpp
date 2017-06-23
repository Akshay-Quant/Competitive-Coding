#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int height[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i = 0; i<n; i++){
		cin>>arr[i]>>height[i];
	}
	long long count;
	if(n == 1)
		count = 1;
	else
		count = 2;
	for(int i = 1; i<n-1; i++){
		if(arr[i] - arr[i-1] > height[i]){
			count++;
		}else if(arr[i+1] - arr[i] > height[i]){
			count++;
			arr[i] = arr[i] + height[i];
		}
	}
	cout<<count<<"\n";
	return 0;
}
