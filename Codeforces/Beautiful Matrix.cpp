#include <bits/stdc++.h>
using namespace std;
int arr[6][6];

int main(){
	int count;
	for(int i = 1; i <= 5; i++){
		for(int j = 1; j <= 5; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 1){
				count = abs(3 - i) + abs(3 - j);
			}
		}
	}
	cout << count << "\n";
	return 0;
}
