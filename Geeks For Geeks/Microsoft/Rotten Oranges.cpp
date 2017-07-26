#include <bits/stdc++.h>
using namespace std;

int arr[102][102];
int n, m;

bool isdelimiter(pair<int, int> t){
	if(t.first == -1 && t.second == -1)
		return true;
	return false;
}

bool issafe(int x, int y){
	if(x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}

int BFS(){
	queue< pair<int, int> > q;
	int ans = 0;
	pair<int, int> temp;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(arr[i][j] == 2){
				temp.first = i;
				temp.second = j;
				q.push(temp);
			}
		}
	}
	temp.first = -1;
	temp.second = -1;
	q.push(temp);
	while(!q.empty()){
		bool flag = false;
		while(!isdelimiter(q.front())){
			temp = q.front();
			if(issafe(temp.first + 1, temp.second) && arr[temp.first + 1][temp.second] == 1){
				if(flag == false){
					flag = true;
					ans++;
				}
				arr[temp.first + 1][temp.second] = 2;
				temp.first++;
				q.push(temp);
				temp.first--;
			}
			if(issafe(temp.first - 1, temp.second) && arr[temp.first - 1][temp.second] == 1){
				if(flag == false){
					flag = true;
					ans++;
				}
				arr[temp.first - 1][temp.second] = 2;
				temp.first--;
				q.push(temp);
				temp.first++;
			}
			if(issafe(temp.first, temp.second + 1) && arr[temp.first][temp.second + 1] == 1){
				if(flag == false){
					flag = true;
					ans++;
				}
				arr[temp.first][temp.second + 1] = 2;
				temp.second++;
				q.push(temp);
				temp.second--;
			}
			if(issafe(temp.first, temp.second - 1) && arr[temp.first][temp.second - 1] == 1){
				if(flag == false){
					ans++;
					flag = true;
				}
				arr[temp.first][temp.second - 1] = 2;
				temp.second--;
				q.push(temp);
				temp.second++;
			}
			q.pop();
		}
		q.pop();
		if(!q.empty()){
			temp.first = -1;
			temp.second = -1;
			q.push(temp);
		}
	}
	bool res = false;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(arr[i][j] == 1){
				res = true;
				break;
			}
		}
		if(res)
			break;
	}
	if(res)
		return -1;
	else
		return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		memset(arr, 0, sizeof(arr));
		cin >> n >> m;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> arr[i][j];
		cout << BFS() << "\n";
	}
	return 0;
}
