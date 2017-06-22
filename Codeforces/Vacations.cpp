#include <bits/stdc++.h>
using namespace std;
int arr[105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	int flag1 = 0;
	int flag2 = 0;
	int count = 0;
	for(int i = 0; i<n; i++){
		if(arr[i] == 0){
			count++;
			flag1 = 0;
			flag2 = 0;
		}else if(arr[i] == 1){
			if(flag1 == 0){
				flag1 = 1;
				flag2 = 0;
			}else{
				count++;
				flag1 = 0;
				flag2 = 0;
			}
		}else if(arr[i] == 2){
			if(flag2 == 0){
				flag2 = 1;
				flag1 = 0;
			}else{
				count++;
				flag1 = 0;
				flag2 = 0;
			}
		}else if(arr[i] == 3){
			if(flag1 == 0 && flag2 == 1){
				flag1 = 1;
				flag2 = 0;
			}else if(flag2 == 0 && flag1 == 1){
				flag2 = 1;
				flag1 = 0;
			}else{
				flag1 = 0;
				flag2 = 0;
			}
		}
	}
	cout<<count<<"\n";
	return 0;
}
