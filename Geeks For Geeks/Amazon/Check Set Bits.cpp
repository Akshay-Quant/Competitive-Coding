#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL):
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		bool flag = false;
		if(n == 0){
			flag = true;
		}
		while(n > 0){
			if((n & 1) == 0){
				flag = true;
				break;
			}
			n = n >> 1;
		}
		if(flag == false)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	return 0;
}
