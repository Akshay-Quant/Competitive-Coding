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
		int c[3] = {0};
		for(int i = 0; i < n; i++)
			c[a[i] % 3]++;
		int res = ((c[0] * (c[0] - 1)) / 2) +
					(c[1] * c[2]) + (c[0] * (c[0] - 1) * (c[0] - 2) / 6) + 
					(c[1] * (c[1] - 1) * (c[1] - 2) / 6) +
					(c[2] * (c[2] - 1) * (c[2] - 2) / 6) +
					(c[0] * c[1] * c[2]);
		cout << res << "\n";
	}
	return 0;
}
