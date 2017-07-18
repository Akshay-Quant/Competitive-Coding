vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> res;
    int j = 0;
    if(A.size() == 1 && A[0] == 0){
        res.push_back(1);
        return res;
    }
    while(A[j] == 0 && j<A.size()){
        j++;
    }
    if(j ==  A.size()){
        res.push_back(1);
        return res;
    }
    int last = A[A.size() - 1] + 1;
    A[A.size() - 1] = last;
    int i;
    for(i = A.size() - 1; i>=j + 1; i--){
        if(A[i] == 10){
            A[i] = 0;
            A[i - 1] += 1;
        }else{
            break;
        }
    }
    if(A[i] == 10){
        res.push_back(1);
        res.push_back(0);
        for(int k = i + 1; k<A.size(); k++){
            res.push_back(A[k]);
        }
    }else{
        for(int k = j; k<A.size(); k++){
            res.push_back(A[k]);
        }
    }
    return res;
}
