#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	string s1,s2;
	cin>>s1>>s2;
	int count1 = 0;
	int count2 = 0;
	int countquestion = 0;
	for(int i = 0; i<s1.length(); i++){
		if(s2[i] == '?')
			countquestion++;
		if(s1[i] == '+')
			count1++;
		else
			count1--;
		if(s2[i] == '+')
			count1--;
		else if(s2[i] == '-')
			count1++;
	}
	for(int i = 0; i<pow(2,countquestion); i++){
		int temp = count1;
		int j = i;
		for(int k = 1; k<=countquestion; k++){
			if((j & 1) == 1){
				temp += -1;
			}else{
				temp += 1;
			}
			j = j/2;
		}
		if(temp == 0){
			count2++;
		}
	}
	cout.precision(20);
	double deno = pow(2,countquestion);
	cout<<(double)count2 / deno<<"\n";
	return 0;
}
