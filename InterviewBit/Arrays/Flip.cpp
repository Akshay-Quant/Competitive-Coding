vector<int> Solution::flip(string A) {
    vector<int> count(A.size());
    for(int i = 0; i<A.size(); i++){
        if(A[i] == '0'){
            count[i] = 1;
        }else{
            count[i] = -1;
        }
    }
    int sum = 0;
    int maxsum = INT_MIN;
    int left = 0, leftindex = 0, rightindex = 0;
    for(int i = 0; i<A.size(); i++){
        sum += count[i];
        if(sum < 0){
            left = i + 1;
            sum = 0;
        }else if(sum > maxsum){
            leftindex = left;
            rightindex = i;
            maxsum = sum;
        }
    }
    vector<int> res;
    if(maxsum <= 0){
        return res;
    }else{
        res.push_back(leftindex + 1);
        res.push_back(rightindex + 1);
        return res;
    }
}
