#include <bits/stdc++.h>
using namespace std;

char find(int level, int num){
	if(level == 1)
		return 'e';
	if((find(level - 1, (num + 1) / 2)) == 'd'){
		if(num % 2 == 0)
			return 'e';
		else
			return 'd';
	}
	if(num % 2 == 0)
		return 'd';
	else
		return 'e';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int level, num;
		cin >> level >> num;
		if(find(level, num) == 'e')
			cout << "Engineer" << "\n";
		else
			cout << "Doctor" << "\n";
	}
	return 0;
}
