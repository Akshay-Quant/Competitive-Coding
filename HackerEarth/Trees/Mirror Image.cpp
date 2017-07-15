#include <bits/stdc++.h>
using namespace std;

char c;
int n, q, res, temp;
int tree[10002][2];

int findmirror(int x, int y){
	if(x == 0 || y == 0)
		return 0;
	if(temp == x)
		return y;
	if(temp == y)
		return x;
	int ans = findmirror(tree[x][0], tree[y][1]);
	if(ans != 0)
		return ans;
	return findmirror(tree[x][1], tree[y][0]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(tree, 0, sizeof(tree));
	cin >> n >> q;
	for(int i = 0; i < n - 1; i++){
		int x, y;
		cin >> x >> y >> c;
		if(c == 'L'){
			tree[x][1] = y;
		}else if(c == 'R'){
			tree[x][0] = y;
		}
	}
	while(q--){
		res = 0;
		cin >> temp;
		res = findmirror(1, 1);
		if(res == 0)
			cout << -1 << "\n";
		else
			cout << res << "\n";
	}
	return 0;
}
