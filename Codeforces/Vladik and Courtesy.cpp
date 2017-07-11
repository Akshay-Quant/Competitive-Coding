#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll a, b;
	cin >> a >> b;
	ll count = 1;
	ll flag = 0;
	while(1){
		if(flag == 0){
			if(a >= count){
				a -= count;
			}else{
				break;
			}
			count++;
			flag = 1;
		}else{
			if(b >= count){
				b -= count;
			}else{
				break;
			}
			count++;
			flag = 0;
		}
	}
	if(flag == 0)
		cout << "Vladik" << "\n";
	else
		cout << "Valera" << "\n";
	return 0;
}
