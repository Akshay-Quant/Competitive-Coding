#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		s += "$";
		int maxi = 0, current = 0;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '<')
				current++;
			else if(s[i] == '=')
				continue;
			else{
				if(maxi < current){
					maxi = current;
				}
				current = 0;
			}
		}
		current = 0;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '>')
				current++;
			else if(s[i] == '=')
				continue;
			else{
				if(maxi < current)
					maxi = current;
				current = 0;
			}
		}
		cout << 1 + maxi << "\n";
	}
	return 0;
}
