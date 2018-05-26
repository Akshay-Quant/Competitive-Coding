#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, curr, back = 0;
        cin >> n >> curr;
        for(int i = 0; i < n; i++){
            char p;
            cin >> p;
            if(p == 'P'){
                int pass;
                cin >> pass;
                back = curr;
                curr = pass;
            }else{
                int temp = back;
                back = curr;
                curr = temp;
            }
        }
        cout << "Player " << curr << "\n";
    }
    return 0;
}
