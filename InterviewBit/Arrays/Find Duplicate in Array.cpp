int Solution::repeatedNumber(const vector<int> &A) {
    vector<bool> visited(A.size(), true);
    for(int i = 0; i<A.size(); i++){
        if(visited[A[i]] == true){
            visited[A[i]] = false;
        }else{
            return A[i];
        }
    }
    return -1;
}
