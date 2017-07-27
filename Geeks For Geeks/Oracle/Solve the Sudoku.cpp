#include <bits/stdc++.h>
using namespace std;

int arr[9][9];

bool issafe(int row, int col, int num){
	for(int i = 0; i < 9; i++){
		if(arr[row][i] == num)
			return false;
	}
	for(int i = 0; i < 9; i++){
		if(arr[i][col] == num)
			return false;
	}
	int i = row / 3;
	int j = col / 3;
	for(int k = i * 3; k < (i + 1) * 3; k++){
		for(int l = j * 3; l < (j + 1) * 3; l++){
			if(arr[k][l] == num)
				return false;
		}
	}
	return true;
}

bool solve(int row, int col){
	if(row == 9)
		return true;
	if(arr[row][col]){
		if(col < 8)
			return solve(row, col + 1);
		else
			return solve(row + 1, 0);
	}
	for(int i = 1; i <= 9; i++){
		if(issafe(row, col, i)){
			arr[row][col] = i;
			if(col < 8){
				if(solve(row,col + 1))
					return true;
			}else if(solve(row + 1, 0))
				return true;
			arr[row][col] = 0;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++)
				cin >> arr[i][j];
		bool temp = solve(0, 0);
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				cout << arr[i][j] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
