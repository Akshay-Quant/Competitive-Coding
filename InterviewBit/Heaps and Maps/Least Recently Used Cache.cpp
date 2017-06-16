map<int,int> m;
int maxi;
queue<int> s;

LRUCache::LRUCache(int capacity) {
    m.erase(m.begin(),m.end());
    while(!s.empty()){
        s.pop();
    }
    maxi=capacity;
}

int LRUCache::get(int key) {
    if(m.find(key)!=m.end()){
        s.push(key);
        return m[key];
    }else{
        return -1;
    }
}

void LRUCache::set(int key, int value) {
    if(maxi>0 && m.find(key)==m.end()){
        s.push(key);
        m[key]=value;
        maxi--;
    }else if(m.find(key)!=m.end()){
        m[key]=value;
        if(s.front()==key){
            s.pop();
        }
        s.push(key);
    }else if(maxi==0){
        int top=s.front();
        s.pop();
        s.push(key);
        m.erase(top);
        m[key]=value;
    }
}
