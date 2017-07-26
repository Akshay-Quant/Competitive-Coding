#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		string s1, s2;
		cin >> s1 >> s2;
		int l1, l2, i = 0, j = 0;
		l1 = s1.size();
		l2 = s2.size();
		bool flag1 = 0, flag2 = 0, res1 = 0, res2 = 0, res = 0;
		while(i < l1 && j < l2){
			if(s1[i] == 'n' && s1[i + 1] == 'g'){
				flag1 = 1;
			}
			if(s2[j] == 'n' && s2[j + 1] == 'g'){
				flag2 = 1;
			}
			if(flag1 == 1 && flag2 == 1){
				i += 2;
				j += 2;
				flag1 = 0;
				flag2 = 0;
				continue;
			}
			if(flag1){
				if(s2[j] >= 'o'){
					res2 = 1;
					break;
				}else{
					res1 = 1;
					break;
				}
			}
			if(flag2){
				if(s1[i] >= 'o'){
					res1 = 1;
					break;
				}else{
					res2 = 1;
					break;
				}
			}
			if(s1[i] != s2[j]){
				if(s1[i] > s2[j]){
					res1 = 1;
					break;
				}else{
					res2 = 1;
					break;
				}
			}
			i++;
			j++;
		}
		if(res1){
			cout << 1 << "\n";
			res = 1;
		}else if(res2){
			cout << -1 << "\n";
			res = 1;
		}
		if(res == 0){
			if(l1 < l2){
				cout << -1 << "\n";
			}else if(l1 > l2){
				cout << 1 << "\n";
			}else{
				cout << 0 << "\n";
			}
		}
	}
	return 0;
}
