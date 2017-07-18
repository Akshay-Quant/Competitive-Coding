vector<int> Solution::wave(vector<int> &A) {
    vector<int> smallest;
    vector<int> greatest;
    sort(A.begin(), A.end());
    smallest = A;
    reverse(A.begin(), A.end());
    greatest = A;
    int i = 0, j = A.size() - 2;
    vector<int> res;
    while(i < A.size() || j >= 0){
        if(j >= 0){
            res.push_back(greatest[j]);
            j -= 2;
        }
        if(i < A.size()){
            res.push_back(smallest[i]);
            i += 2;
        }
    }
    return res;
}
