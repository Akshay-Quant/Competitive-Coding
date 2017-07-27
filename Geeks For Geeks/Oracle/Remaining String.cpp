#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		char c;
		int count, index = 0, i;
		cin >> c >> count;
		if(count == 0){
			cout << s << "\n";
		}else{
			bool flag = false;
			for(i = 0; i < s.size(); i++){
				if(tolower(s[i]) == c)
					index++;
				if(index == count)
					break;
			}
			if(i < s.size() - 1){
				count = s.size() - i - 1;
				cout << s.substr(i + 1, count) << "\n";
			}else{
				cout << "Empty string" << "\n";
			}
		}
	}
	return 0;
}
