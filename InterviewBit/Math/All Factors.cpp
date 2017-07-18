vector<int> Solution::allFactors(int A) {
    vector <int> res;
    for(int i=1;i<=(sqrt(A));i++){
        if(A%i==0){
            if(A/i==i){
                res.push_back(i);
            }else{
                res.push_back(i);
                res.push_back(A/i);
            }
        }
    }
    sort(res.begin(),res.end());
    return res;
}
