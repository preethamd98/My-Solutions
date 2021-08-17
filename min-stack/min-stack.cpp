class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int,int>> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        if(minStack.size()==0){minStack.emplace(val,val);return;}
        minStack.emplace(val,min(val,minStack.top().second));
        return;
    }
    
    void pop() {
        minStack.pop();
        return;
    }
    
    int top() {
        return minStack.top().first;
    }
    
    int getMin() {
        return minStack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */