#include <bits/stdc++.h>
using namespace std;
set<string> v;
int t, add, shift;

void DFS(string s){
	v.insert(s);
	string temp = s;
	int l = temp.length();
	for(int i = 0; i < l; i++){
		temp[(i + shift) % l] = s[i];
	}
	if(v.find(temp) == v.end())
		DFS(temp);
	temp = s;
	for(int i = 0; i < l; i++){
		if(i % 2 == 1){
			temp[i] = '0' + (temp[i] - '0' + add) % 10;
		}
	}
	if(v.find(temp) == v.end())
		DFS(temp);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while(t--){
		string input;
		cin >> input;
		cin >> add >> shift;
		v.clear();
		DFS(input);
		cout << *(v.begin()) << "\n";
	}
	return 0;
}
