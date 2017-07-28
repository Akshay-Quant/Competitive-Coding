#include <bits/stdc++.h>
using namespace std;

int arr[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
string day[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int d, m, y;
		cin >> d >> m >> y;
		if(m < 3)
			y -= 1;
		int res = (y + (y /4) - (y / 100) + (y / 400) + arr[m - 1] + d) % 7;
		cout << day[res] << "\n";
	}
	return 0;
}
