#include <bits/stdc++.h>
using namespace std;

int main(){
	string s, fin;
	cin >> s;
	for(int i = 0; i < s.length(); i++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			s[i] += 32;
		}
		if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'y'){
			fin.append(1, '.');
			fin.append(1, s[i]);
		}
	}
	cout << fin << "\n";
	return 0;
}
