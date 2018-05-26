#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, x, flag = 0, res;
    cin >> n >> x;
    ll arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > x)
            flag++;
        if(flag > 1)
            break;
        res = i - flag + 1;
    }
    cout << res << "\n";
    return 0;
}
