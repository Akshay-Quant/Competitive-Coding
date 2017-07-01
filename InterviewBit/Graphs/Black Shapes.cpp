int rownum[] = {-1, 0, 1, 0};
int colnum[] = {0, 1, 0, -1};

bool issafe(vector<string> &A, vector<vector<bool> > &visited, int row, int col){
    if(row >= 0 && row < A.size() && col >= 0 && col < A[0].size() && A[row][col] == 'X' && !visited[row][col]){
        return true;
    }
    return false;
}

void DFS(vector<string> &A, vector<vector<bool> > &visited, int row, int col){
    visited[row][col] = true;
    for(int i = 0; i<4; i++){
        if(issafe(A, visited, row + rownum[i], col + colnum[i]) == true){
            DFS(A, visited, row + rownum[i], col + colnum[i]);
        }
    }
}

int Solution::black(vector<string> &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    int res = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(visited[i][j] == false && A[i][j] == 'X'){
                DFS(A, visited, i, j);
                res++;
            }
        }
    }
    return res;
}
