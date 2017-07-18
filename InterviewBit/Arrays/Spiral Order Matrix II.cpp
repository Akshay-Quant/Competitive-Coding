vector<vector<int> > Solution::generateMatrix(int A) {
    int left = 0, right = A - 1, top = 0, bottom = A - 1;
    int counter = 1;
    int direction = 0;
    vector<vector<int> > res(A, vector<int>(A));
    while(top <= bottom && left <= right){
        if(direction == 0){
            for(int i = left; i<=right; i++){
                res[top][i] = counter;
                counter++;
            }
            top++;
            direction = 1;
        }else if(direction == 1){
            for(int i = top; i<= bottom; i++){
                res[i][right] = counter;
                counter++;
            }
            right--;
            direction = 2;
        }else if(direction == 2){
            for(int i = right; i>=left; i--){
                res[bottom][i] = counter;
                counter++;
            }
            bottom--;
            direction = 3;
        }else if(direction == 3){
            for(int i = bottom; i>=top; i--){
                res[i][left] = counter;
                counter++;
            }
            left++;
            direction = 0;
        }
    }
    return res;
}
