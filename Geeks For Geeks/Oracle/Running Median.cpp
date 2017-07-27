#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	priority_queue<int> max_left;
	priority_queue<int, vector<int>, greater<int> > min_right;
	int median = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(max_left.size() > min_right.size()){
			if(x < median){
				min_right.push(max_left.top());
				max_left.pop();
				max_left.push(x);
			}else{
				min_right.push(x);
			}
			median = (min_right.top() + max_left.top()) / 2.0;
		}else if(max_left.size() == min_right.size()){
			if(x < median){
				max_left.push(x);
				median = max_left.top();
			}else{
				min_right.push(x);
				median = min_right.top();
			}
		}else{
			if(x < median){
				max_left.push(x);
			}else{
				max_left.push(min_right.top());
				min_right.pop();
				min_right.push(x);
			}
			median = (min_right.top() + max_left.top()) / 2.0;
		}
		cout << median << "\n";
	}
	return 0;
}
