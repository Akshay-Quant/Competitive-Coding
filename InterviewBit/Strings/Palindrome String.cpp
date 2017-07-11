string convert(string A){
    string res;
    for(int i = 0; i < A.length(); i++){
        if(A[i] >= 'A' && A[i] <= 'Z'){
            A[i] += 32;
        }
        if((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= '0' && A[i] <= '9')){
            res.push_back(A[i]);
        }
    }
    return res;
}

int Solution::isPalindrome(string A) {
    A = convert(A);
    int i = 0, j = A.length() - 1;
    while(i < j){
        if(A[i] == A[j]){
            i++;
            j--;
        }else{
            return 0;
        }
    }
    return 1;
}
