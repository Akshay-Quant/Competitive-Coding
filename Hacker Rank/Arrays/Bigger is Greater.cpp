#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        bool val=next_permutation(s.begin(),s.end());
        if(val){
            cout<<s<<endl;
        }else{
            cout<<"no answer"<<endl;    
        }
    }
    return 0;
}
