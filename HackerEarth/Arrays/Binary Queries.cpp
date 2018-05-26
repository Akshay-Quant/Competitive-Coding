#include <bits/stdc++.h>
using namespace std;
int arr[1000005]; //try to initialize all arrays globally as global arrays are by default 0
 
int main(){
    ios_base::sync_with_stdio(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int position;
			cin>>position;
			if(arr[position]==0){
				arr[position]=1;
			}else{
				arr[position]=0;
			}
		}else{
			int l,r;
			cin>>l>>r;
			if(arr[r]==0){
				cout<<"EVEN"<<endl;
			}else{
				cout<<"ODD"<<endl;
			}
		}
	}
	return 0;
}
