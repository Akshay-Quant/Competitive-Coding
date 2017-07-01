void search(vector<vector<char> > &A, int row, int col, char prev, char newc){
    if(row < 0 || row >= A.size() || col < 0 || col >= A[0].size()){
        return;
    }
    if(A[row][col] != prev){
        return;
    }
    A[row][col] = newc;
    search(A, row - 1, col, prev, newc);
    search(A, row, col + 1, prev, newc);
    search(A, row + 1, col, prev, newc);
    search(A, row, col - 1, prev, newc);
}

void Solution::solve(vector<vector<char> > &A) {
    for(int i = 0; i<A.size(); i++){
        for(int j = 0; j<A[0].size(); j++){
            if(A[i][j] == 'O'){
                A[i][j] = '-';
            }
        }
    }
    for(int i = 0; i<A.size(); i++){
        if(A[i][0] == '-')
            search(A, i, 0, '-', 'O');
    }
    for(int i = 0; i<A.size(); i++){
        if(A[i][A[0].size() - 1] == '-')
            search(A, i, A[0].size()-1, '-', 'O');
    }
    for(int i = 0; i<A[0].size(); i++){
        if(A[0][i] == '-')
            search(A, 0, i, '-', 'O');
    }
    for(int i = 0; i<A[0].size(); i++){
        if(A[A.size() - 1][i] == '-')
            search(A, A.size() - 1, i, '-', 'O');
    }
    for(int i = 0; i<A.size(); i++){
        for(int j = 0; j<A[0].size(); j++){
            if(A[i][j] == '-')
                A[i][j] = 'X';
        }
    }
}
