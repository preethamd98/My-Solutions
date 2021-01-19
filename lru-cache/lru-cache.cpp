class LRUCache {
public:
    unordered_map<int,list<pair<int,int>>::iterator> M;
    list<pair<int,int>> L;
    int capacity = 0;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(M.find(key)==M.end()){
            return -1;
        }
        int value = M[key]->second;
        L.erase(M[key]);
        L.push_front({key,value});
        M[key] = L.begin();
        return value;
    }
    
    void put(int key, int value) {
        if(M.find(key)!=M.end()){ // Update Step;
            L.erase(M[key]);
            L.push_front(make_pair(key,value));
            M[key] = L.begin();
            return;
        }
        L.push_front({key,value});
        M[key] = L.begin();
        if(M.size()>capacity){ // Eviction step;
            M.erase(L.rbegin()->first);
            L.pop_back();
        }
    }
};
​
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
