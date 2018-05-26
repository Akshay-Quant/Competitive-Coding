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
        int n;
        cin >> n;
        int arr1[n], arr2[n], freq1[101] = {0}, freq2[101] = {0};
        for(int i = 0; i < n; i++)
        {
            cin >> arr1[i];
            freq1[arr1[i]]++;
        }
        for(int i = 0; i < n; i++)
        {
            cin >> arr2[i];
            freq2[arr2[i]]++;
        }
        int max1 = 0, ele1 = 0, max2 = 0, ele2 = 0;
        for(int i = 0; i < 101; i++)
        {
            if(freq1[i] >= max1)
            {
                max1 = freq1[i];
                ele1 = i;
            }
            if(freq2[i] >= max2)
            {
                max2 = freq2[i];
                ele2 = i;
            }
        }
        if(ele1 > ele2)
            cout << "Rupam" << "\n";
        else if(ele1 < ele2)
            cout << "Ankit" << "\n";
        else
            cout << "Tie" << "\n";
    }
    return 0;
}
