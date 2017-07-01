int rownum[] = {-1, 0, 1, 0};
int colnum[] = {0, 1, 0, -1};

bool issafe(vector<string> &A, string B, int row, int col, int index){
    if(row >= 0 && row < A.size() && col >= 0 && col < A[0].size() && A[row][col] == B[index]){
        return true;
    }
    return false;
}

bool search(vector<string> &A, string B, int row, int col, int index){
    if(index == B.length())
        return 1;
    for(int i = 0; i<4; i++){
        if(issafe(A, B, row + rownum[i], col + colnum[i], index)){
            if(search(A, B, row + rownum[i], col + colnum[i], index + 1))
                return true;
        }
    }
    return false;
}

int Solution::exist(vector<string> &A, string B) {
    for(int i = 0; i<A.size(); i++){
        for(int j = 0; j<A[0].size(); j++){
            if(A[i][j] == B[0]){
                if(search(A, B, i, j, 1))
                    return 1;
            }
        }        
    }
    return 0;
}
