#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int x, ans = 0;
    stack<int> st;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        if(x == 0 && !st.empty())
        {
            st.pop();
        }else
        {
            st.push(x);
        }
    }
    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    cout << ans << "\n";
    return 0;
}
