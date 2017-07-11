int Solution::solve(string A) {
    string rev = A;
    reverse(rev.begin(), rev.end());
    string res = A + "$" + rev;
    vector<int> lps(res.length());
    int l = 0;
    int i = 1;
    lps[0] = 0;
    while(i < res.length()){
        if(res[i] == res[l]){
            l++;
            lps[i] = l;
            i++;
        }else{
            if(l != 0){
                l = lps[l - 1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return (A.length() - lps[res.length() - 1]);
}
