vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> res;
    vector<int> next;
    vector<int> prime;
    vector<int> current;
    prime.push_back(A);
    prime.push_back(B);
    prime.push_back(C);
    for(int i = 0; i<3; i++)
        current.push_back(-1);
    next.push_back(A);
    next.push_back(B);
    next.push_back(C);
    for(int i = 0; i<D; i++){
        int ans = min(next[0], min(next[1], next[2]));
        res.push_back(ans);
        for(int i = 0; i<3; i++){
            if(ans == next[i]){
                current[i]++;
                next[i] = res[current[i]] * prime[i];
            }
        }
    }
    return res;
}
