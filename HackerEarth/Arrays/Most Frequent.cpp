#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, curr = 0, maxi = 0, num;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    num = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i - 1]){
            curr++;
        }else{
            if(curr > maxi){
                maxi = curr;
                num = arr[i - 1];
            }
            curr = 1;
        }
    }
    if(curr > maxi){
        maxi = curr;
        num = arr[n - 1];
    }
    cout << num << "\n";
    return 0;
}
