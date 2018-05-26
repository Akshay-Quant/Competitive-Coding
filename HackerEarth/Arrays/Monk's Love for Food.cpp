#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    stack<int> st;
    cin >> n;
    while(n--)
    {
        int x, c;
        cin >> x;
        if(x == 2)
        {
            cin >> c;
            st.push(c);
        }else
        {
            if(st.empty())
            {
                cout << "No Food" << "\n";
            }else
            {
                cout << st.top() << "\n";
                st.pop();
            }
        }
    }
    return 0;
}
