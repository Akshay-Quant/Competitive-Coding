#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, s, taxi;
	cin >> n;
	int count[5] = {0};
	for(int i = 0; i < n; i++){
		cin >> s;
		count[s]++;
	}
	taxi = count[4] + count[3] + (count[2] / 2);
	count[1] -= count[3];
	if(count[2] % 2 == 1){
		taxi += 1;
		count[1] -= 2;
	}
	if(count[1] > 0){
		taxi += (count[1] + 3)/ 4;
	}
	cout << taxi << "\n";
	return 0;
}
