#include <bits/stdc++.h>
using namespace std;
int freq[1005];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q, in;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }
    cin >> q;
    while(q--){
        cin >> in;
        if(freq[in] == 0)
            cout << "NOT PRESENT" << "\n";
        else
            cout << freq[in] << "\n";
    }
    return 0;
}
