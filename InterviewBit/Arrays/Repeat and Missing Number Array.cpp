vector<int> Solution::repeatedNumber(const vector<int> &A) {
    
    long long sum1 = 0, sqr1 = 0, temp;
    for(int i = 0; i<A.size(); i++){
        temp = A[i];
        sum1 += temp;
        sqr1 += (temp*temp);
        sum1 -= (i+1);
        sqr1 -= ((long long)(i+1)*(long long)(i+1));
    }
    sqr1 /= sum1;
    vector <int> res;
    int A1 = (int) ((sqr1 + sum1) / 2);
    int B1 = (int) (sqr1 - A1);
    res.push_back(A1);
    res.push_back(B1);
    return res;
}
