#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	while(t--){
		s = "";
		getline(cin, s);
		int i = 0;
		string res;
		vector<int> space;
		while(i < s.length()){
			if(s[i] == ' '){
				space.push_back(i);
				res.push_back('.');
			}
			if(s[i] >= 'A' && s[i] <= 'Z'){
				s[i] += 32;
			}
			res.push_back(s[i]);
			i++;
		}
		if(space.size() > 0){
			string ans;
			ans += (res[0] - 32);
			ans += ". ";
			for(int j = 0; j<space.size() - 1; j++){
				ans += (res[space[j] + 2] - 32);
				ans += ". ";
			}
			ans += s[space[space.size() - 1] + 1] - 32;
			for(int j = space[space.size() - 1] + 2; j<s.length(); j++){
				ans += s[j];
			}
			cout << ans << "\n";
		}else{
			res[0] -= 32;
			cout << res << "\n";
		}
	}
	return 0;
}
