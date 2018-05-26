#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int res[n];
    int maxi = 0, j = 0;
    for(int i = n - 1; i >= 0; i--){
        if(maxi <= arr[i]){
            res[j++] = arr[i];
            maxi = arr[i];
        }
    }
    for(j = j - 1; j >= 0; j--){
        cout << res[j] << " ";
    }
    return 0;
}
