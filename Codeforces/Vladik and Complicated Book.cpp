#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> p;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		p.push_back(temp);
	}
	vector<pair < pair <int, int> , int > > v;
	for(int i = 0; i < m; i++){
		int t1, t2, x;
		cin >> t1 >> t2 >> x;
		v.push_back(make_pair(make_pair(t1 - 1, t2), x - 1));
	}
	vector<int> t;
	for(int i = 0; i < m; i++){
		t = p;
		int t1 = t[v[i].second];
		sort(t.begin() + v[i].first.first, t.begin() + v[i].first.second);
		int t2 = t[v[i].second];
		if(t1 == t2){
			cout << "Yes" << "\n";
		}else{
			cout << "No" << "\n";
		}
	}
	return 0;
}
