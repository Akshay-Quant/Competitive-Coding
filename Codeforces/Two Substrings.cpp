#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	if(s.length()<=3){
		cout<<"NO"<<endl;
	}else{
		int i1=s.find("AB");
		int i2=s.find("BA",i1+2);
		int i3=s.find("BA");
		int i4=s.find("AB",i3+2);
		if((i1!=-1 && i2!=-1) || (i3!=-1 && i4!=-1)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
