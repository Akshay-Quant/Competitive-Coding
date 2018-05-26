#include <bits/stdc++.h>
using namespace std;
stack <int> s;

int main()
{
    int n,q,x;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>q>>x;
    int i=0,sum=0,flag=0;
    while(q--){
        string str;
        cin>>str;
        if(str=="Harry"){
            s.push(arr[i++]);
            sum=sum+s.top();
            if(sum==x){
                cout<<s.size()<<endl;
                flag=1;
                break;
            }
        }else if(str=="Remove"){
            sum=sum-s.top();
            s.pop();
        }
    }
    if(flag==0)
        cout<<"-1"<<endl;
    return 0;
}
