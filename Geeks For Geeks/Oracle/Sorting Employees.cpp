#include <bits/stdc++.h>
using namespace std;

struct Emp{
	string name;
	int sal;
};

bool comp(Emp e1, Emp e2){
	if(e1.sal == e2.sal)
		return e1.name < e2.name;
	return e1.sal < e2.sal;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		Emp arr[n];
		for(int i = 0; i < n; i++)
			cin >> arr[i].name >> arr[i].sal;
		sort(arr, arr + n, comp);
		for(int i = 0; i < n; i++)
			cout << arr[i].name << " " << arr[i].sal << " ";
		cout << "\n";
	}
	return 0;
}
