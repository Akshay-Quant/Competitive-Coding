#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		int flag = 0;
		for(int i = 0; i < n; i++){
			if(a[i] == 1){
				cout << i << "\n";
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			cout << -1 << "\n";
	}
	return 0;
}
