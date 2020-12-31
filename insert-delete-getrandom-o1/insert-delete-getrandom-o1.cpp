class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> m;
    vector<int> vec;
    
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) != m.end()) {
            return false;
        }
        m[val] = vec.size();
        vec.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end()) {
            return false;
        }
        int index = m[val];
        int endVal = vec[vec.size()-1];
        if(index != vec.size()-1) {   
            swap(vec[index], vec[vec.size()-1]);
            m[endVal] = index;
        }
        vec.pop_back();
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int randIndex = rand()%vec.size();
        return vec[randIndex];
        
    }
};
​
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
