#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[6][6];
    int i,j,k,sum=0;
    for(i = 0;i < 6;i++){
       for(j = 0;j < 6;j++){
          cin >> arr[i][j];
       }
    }
    int maxsum=-64;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            sum=arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
            if(sum>maxsum)
                maxsum=sum;
            sum=0;
        }
    }
    cout<<maxsum;
    return 0;
}
