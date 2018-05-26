#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[1000005], front[1000005], back[1000005];
stack<ll> st;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i++){
        if(st.empty() || arr[st.top()] >= arr[i])
            st.push(i);
        else{
            while(!st.empty() && arr[st.top()] < arr[i]){
                front[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        front[st.top()] = -1;
        st.pop();
    }
    for(int i = n; i > 0; i--){
        if(st.empty() || arr[st.top()] >= arr[i])
            st.push(i);
        else{
            while(!st.empty() && arr[st.top()] < arr[i]){
                back[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        back[st.top()] = -1;
        st.pop();
    }
    for(int i = 1; i <= n; i++){
        cout << front[i] + back[i] << " ";
    }
    return 0;
}
