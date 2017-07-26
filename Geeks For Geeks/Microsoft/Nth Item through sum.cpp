#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, m, count;
		cin >> n >> m;
		int a1[n], a2[m];
		for(int i = 0; i < n; i++)
			cin >> a1[i];
		for(int i = 0 ; i < m; i++)
			cin >> a2[i];
		cin >> count;
		set<int> s;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				s.insert(a1[i] + a2[j]);
			}
		}
		if(s.size() < count)
			cout << -1 << "\n";
		else{
			set<int>::iterator it = s.begin();
			for(int i = 1; i < count; i++)
				it++;
			cout << *it << "\n";
		}
	}
	return 0;
}
