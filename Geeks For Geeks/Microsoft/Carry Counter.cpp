#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin >> t;
	while(t--){
		ll n1, n2;
		cin >> n1 >> n2;
		if(n1 < n2)
			swap(n1, n2);
		ll count = 0, carry = 0;
		while(n1 > 0 || n2 > 0){
			ll t1 = n1 % 10;
			ll t2 = n2 % 10;
			if((t1 +t2 + carry) >= 10){
				carry = (t1 +t2 + carry) / 10;
				count++;
			}else{
				carry = 0;
			}
			n1 = n1 / 10;
			n2 = n2 / 10;
		}
		if(((carry + n1) % 10) >= 10)
			count++;
		cout << count << "\n";
	}
	return 0;
}
