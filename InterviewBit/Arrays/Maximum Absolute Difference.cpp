int Solution::maxArr(vector<int> &A) {
    int res = INT_MIN;
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, max4 = INT_MIN;
    for(int i = 0; i<A.size(); i++){
        max1 = max(max1, A[i] + i);
        max2 = max(max2, A[i] - i);
        max3 = max(max3, -A[i] + i);
        max4 = max(max4, -A[i] - i);
    }
    for(int i = 0; i<A.size(); i++){
        res = max(res, max1 - A[i] - i);
        res = max(res, max2 - A[i] + i);
        res = max(res, max3 + A[i] -i);
        res = max(res, max4 + A[i] + i);
    }
    return res;
}
