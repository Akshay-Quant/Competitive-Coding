#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s, s1;
		getline(cin, s);
		s = "";
		getline(cin, s);
		s += " ";
		map<string, int> m;
		int l = s.length();
		for(int i = 0; i < l; i++){
			if(s[i] == ' '){
				if(m.find(s1) == m.end()){
					m[s1] = 1;
				}else{
					m[s1]++;
				}
				s1 = "";
			}else{
				s1 += s[i];
			}
		}
		int firstmax = 0, secondmax = 0;
		map<string, int>::iterator it;
		for(it = m.begin(); it != m.end(); it++){
			if(it -> second > firstmax){
				secondmax = firstmax;
				firstmax = it -> second;
			}else if(it -> second > secondmax && it -> second != firstmax){
				secondmax = it -> second;
			}
		}
		for(it = m.begin(); it != m.end(); it++){
			if(it -> second == secondmax){
				cout << it -> first << "\n";
			}
		}
	}
	return 0;
}
