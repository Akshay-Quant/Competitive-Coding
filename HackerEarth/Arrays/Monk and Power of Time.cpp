#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    queue<int> q1, q2;
    int n, x, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        q1.push(x);
    }
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        q2.push(x);
    }
    while(!q2.empty())
    {
        if(q1.front() == q2.front())
        {
            ans++;
            q1.pop();
            q2.pop();
        }else
        {
            ans++;
            int t = q1.front();
            q1.pop();
            q1.push(t);
        }
    }
    cout << ans << "\n";
    return 0;
}
