/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool comp(const struct Interval P,const struct Interval Q){
    return P.start<Q.start; 
 }
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    sort(A.begin(),A.end(),comp);
    vector<Interval> res;
    stack<Interval> s;
    s.push(A[0]);
    for(int i=0;i<A.size();i++){
        struct Interval t=s.top();
        if(t.end<A[i].start){
            s.push(A[i]);
        }else if(t.end<=A[i].end){
            t.end=A[i].end;
            s.pop();
            s.push(t);
        }
    }
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    sort(res.begin(),res.end(),comp);
    return res;
}
