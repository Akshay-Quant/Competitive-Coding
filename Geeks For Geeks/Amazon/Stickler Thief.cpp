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
		int inc = a[0], exc = 0;
		int currmax;
		for(int i = 1; i < n; i++){
			currmax = max(exc, inc);
			inc = exc + a[i];
			exc = currmax;
		}
		cout << max(inc, exc) << "\n";
	}
	return 0;
}
