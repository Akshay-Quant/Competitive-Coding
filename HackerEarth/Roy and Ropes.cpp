#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll upper[n], lower[n];
		for(int i = 0; i < n - 1; i++)
			cin >> upper[i];
		for(int i = 0; i < n - 1; i++)
			cin >> lower[i];
		ll res = n;
		for(int i = 0; i < n -1; i++){
			ll temp = i + 1 + max(upper[i], lower[i]);
			res = max(res, temp);
		}
		cout << res << "\n";
	}
	return 0;
}
