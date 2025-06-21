class MinStack {
public:
    stack<int>  data;   
    stack<int>  min_data;

    MinStack() {

    }
    
    void push(int val) {
        data.push(val);
        if (min_data.empty() or val < min_data.top()) {
            min_data.push(val);
        } else {
            min_data.push(min_data.top());
        }
    }
    
    void pop() {
        data.pop(); 
        min_data.pop();
    }
    
    int top() {
        return data.top(); 
    }
    
    int getMin() {
        return min_data.top(); 
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
