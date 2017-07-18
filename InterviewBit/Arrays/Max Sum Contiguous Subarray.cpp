int Solution::maxSubArray(const vector<int> &A) {
    int maxsum = INT_MIN;
    int maxtillhere = 0;
    for(int i = 0; i<A.size(); i++){
        maxtillhere += A[i];
        if(maxsum < maxtillhere){
            maxsum = maxtillhere;
        }
        if(maxtillhere < 0){
            maxtillhere = 0;
        }
    }
    return maxsum;
}
