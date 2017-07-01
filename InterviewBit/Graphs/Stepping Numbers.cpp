void BFS(int A, int B, int index, vector<int> &res){
    queue<int> q;
    q.push(index);
    while(!q.empty()){
        int num = q.front();
        q.pop();
        if(num >= A && num <= B){
            res.push_back(num);
        }
        if(num == 0 || num > B)
            continue;
        int digit = num % 10;
        int num1 = num * 10 + (digit + 1);
        int num2 = num * 10 + (digit - 1);
        if(digit == 0){
            q.push(num1);
        }else if(digit == 9){
            q.push(num2);
        }else{
            q.push(num1);
            q.push(num2);
        }
    }
}

vector<int> Solution::stepnum(int A, int B) {
    vector<int> res;
    for(int i = 0; i<=9; i++){
        BFS(A, B, i, res);
    }
    sort(res.begin(), res.end());
    return res;
}
