class MaxStack {
public:
    stack<pair<int,int>> maxStack;
    MaxStack() {
        
    }
    
    void push(int x) {
        if(maxStack.size()==0){
            maxStack.emplace(x,x);
            return;
        }
        maxStack.emplace(x,max(x,maxStack.top().second));
        return;
    }
    
    int pop() {
        int retValue = maxStack.top().first;
        maxStack.pop();
        return retValue;
    }
    
    int top() {
        return maxStack.top().first;
    }
    
    int peekMax() {
        return maxStack.top().second;
    }
    
    int popMax() {
        int maxValue = peekMax();
        stack<int> temp;
        while(maxValue!=top()){
            temp.push(top());
            pop();
        }
        int retValue = top();
        pop();
        while(!temp.empty()){
            push(temp.top());
            temp.pop();
        }
        return retValue;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */