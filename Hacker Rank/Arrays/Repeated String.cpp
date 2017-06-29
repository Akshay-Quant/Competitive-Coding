#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;


int main(){
    string s;
    cin >> s;
    long n;
    cin >> n;
    long l=s.length();
    int count=0;
    for(int j=0;j<s.length();j++){
        if(s[j]=='a')
            count++;
    }
    int count1=0;
    long rep=n/l;
    long rem=n%l;
    for(int j=0;j<rem;j++){
        if(s[j]=='a')
            count1++;
    }
    long total=(rep*count)+count1++;
    cout<<total;
    return 0;
}
