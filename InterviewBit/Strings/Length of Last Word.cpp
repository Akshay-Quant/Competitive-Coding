int Solution::lengthOfLastWord(const string &A) {
    int current = 0, last = 0;
    int i = 0;
    while(i < A.length()){
        if(A[i] != ' '){
            current++;
        }else if(A[i] == ' '){
            if(current > 0)
                last = current;
            current = 0;
        }
        i++;
    }
    if(current > 0){
        last = current;
    }
    return last;
}
