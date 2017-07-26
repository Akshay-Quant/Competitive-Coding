#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	while(t--){
		s = "";
		getline(cin, s);
		set<char> vis;
		string s1;
		for(int i = 0; i < s.size(); i++){
			if(vis.find(tolower(s[i])) == vis.end()){
				vis.insert(tolower(s[i]));
				s1 += s[i];
			}else{
				vis.erase(tolower(s[i]));
			}
		}
		cout << s1 << "\n";
	}
	return 0;
}
