class FreqStack {
public:
    unordered_map<int,int> freqMap;
    map<int,stack<int>> M;
    FreqStack() {
        
    }
    void push(int x) {
        freqMap[x]++;
        M[freqMap[x]].push(x);
    }
    
    int pop() {
        auto it = M.rbegin();
        int value = it->second.top();
        it->second.pop();
        if(it->second.size()==0){
            M.erase(it->first);
        }
        freqMap[value]--;
        return value;
    }
};
​
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
