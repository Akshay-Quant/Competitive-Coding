#include <bits/stdc++.h>
using namespace std;

char boggle[9][9];
int n, m, num;
string s;
bool visited[9][9] = {false};
vector<string> dict;

int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool issafe(int i, int j){
	if(i >= 0 && i < n && j >= 0 && j < m && visited[i][j] == false)
		return true;
	return false;
}

bool isdict(){
	for(int i = 0; i < dict.size(); i++){
		if(s.compare(dict[i]) == 0)
			return true;
	}
	return false;
}

void DFS(int i, int j){
	visited[i][j] = true;
	s += boggle[i][j];
	if(isdict())
		cout << s << " ";
	for(int k = 0; k < 8; k++){
		if(issafe(i + row[k], j + col[k])){
			DFS(i + row[k], j + col[k]);
		}
	}
	s.erase(s.size() - 1);
	visited[i][j] = false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		cin >> num;
		string temp;
		getline(cin, temp);
		temp = "";
		getline(cin, temp);
		temp += " ";
		for(int i = 0; i < temp.size(); i++){
			if(temp[i] == ' '){
				dict.push_back(s);
				s = "";
			}else{
				s += temp[i];
			}
		}
		s = "";
		cin >> n >> m;
		memset(boggle, 0, sizeof(boggle));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> boggle[i][j];
			}
		}
		memset(visited, false, sizeof(visited));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				DFS(i, j);
			}
		}
		dict.clear();
		cout << "\n";
	}
	return 0;
}
