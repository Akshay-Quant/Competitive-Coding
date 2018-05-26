#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[200005];
stack <ll> s;

int main()
{
    ll n,count=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    s.push(0);
    for(int i=1;i<=n;i++){
        if(arr[i]>0)
            s.push(i);
        else{
            ll temp=s.top();
            s.pop();
            if(arr[temp]==-arr[i]){
                if(!s.empty()){
                    count=max(count,i-s.top());
                }else{
                    s.push(i);
                }
            }else{
                s.push(i);
            }
        }
    }
    cout<<count<<endl;
    return 0;
}
