#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n, min_here, count = 1;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        min_here = arr[0];
        for(int i = 1; i < n; i++)
        {
            if(min_here >= arr[i])
            {
                min_here = arr[i];
                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}
