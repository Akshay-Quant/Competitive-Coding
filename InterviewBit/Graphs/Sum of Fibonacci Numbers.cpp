int Solution::fibsum(int A) {
    vector<int> fibo;
    fibo.push_back(1);
    fibo.push_back(1);
    int sum = 0, i = 2;
    while(sum <= A){
        sum = fibo[i - 2] + fibo[i - 1];
        fibo.push_back(sum);
        i++;
    }
    i = fibo.size() - 1;
    int res = 0;
    while(A > 0 && i >= 0){
        if(fibo[i] == A){
            res++;
            return res;
        }else if(fibo[i] < A){
            res++;
            A -= fibo[i];
            i--;
        }else{
            i--;
        }
    }
}
