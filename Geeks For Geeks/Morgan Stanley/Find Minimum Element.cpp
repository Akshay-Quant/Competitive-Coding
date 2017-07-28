#include <bits/stdc++.h>
using namespace std;

int arr[505];

int findmin(int low, int high){
	int mid = (low + high) / 2;
	if(high < low)
		return arr[0];
	if(high == low)
		return arr[low];
	if(mid < high && arr[mid] > arr[mid + 1])
		return arr[mid + 1];
	if(low < mid && arr[mid - 1] > arr[mid])
		return arr[mid];
	if(arr[high] > arr[mid])
		return findmin(low, mid - 1);
	return findmin(mid + 1, high);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		memset(arr, 0, sizeof(arr));
		int n;
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		cout << findmin(0, n - 1) << "\n";
	}
	return 0;
}
