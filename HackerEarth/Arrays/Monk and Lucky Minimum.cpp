#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n],mini=INT_MAX,freq,flag;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(mini>arr[i]){
                mini=arr[i];
                freq=1;
                flag=1;
            }else if(mini<arr[i]){
                flag=-1;
            }else{
                flag=0;
            }
            if(flag==0){
                freq++;
            }
        }
        if((freq%2)==0)
            cout<<"Unlucky"<<endl;
        else
            cout<<"Lucky"<<endl;
    }
    return 0;
}
