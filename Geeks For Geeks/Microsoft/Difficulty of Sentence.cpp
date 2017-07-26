#include <bits/stdc++.h>
using namespace std;

bool isvowel(char c){
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	s = "";
	while(t--){
		getline(cin, s);
		int cc = 0, ccc = 0, cv = 0, hw = 0, ew = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] != ' ' && isvowel(tolower(s[i]))){
				cv++;
				ccc = 0;
			}else if(s[i] != ' '){
				cc++;
				ccc++;
			}
			if(ccc == 4){
				hw++;
				while(i< s.size() && s[i] != ' ')
					i++;
				ccc = 0;
				cc = 0;
				cv = 0;
			}else if(i < s.size() && (s[i] == ' ' || i == s.size() - 1)){
				if(cc > cv)
					hw++;
				else
					ew++;
				ccc = 0;
				cc = 0;
				cv = 0;
			}
		}
		cout << (5 * hw) + (3 * ew) << "\n"; 
	}
	return 0;
}
