void Solution::nextPermutation(vector<int> &A) {
    int flag = 0;
    int index1, index2;
    for(int i = A.size() - 1; i>=1; i--){
        if(A[i] > A[i - 1]){
            index1 = i - 1;
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        for(int i = A.size() - 1; i>index1; i--){
            if(A[i] > A[index1]){
                index2 = i;
                break;
            }
        }
        swap(A[index1], A[index2]);
        reverse(A.begin() + index1 + 1, A.end());
    }else if(flag == 0){
        sort(A.begin(), A.end());
    }
}
