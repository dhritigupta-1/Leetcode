class MinStack {
public:
    stack<long long> s1;
    long long minl;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s1.empty()){
            s1.push(1);
            minl = val;
        }
        else{
            long long diff = (long long) val - minl ;
            s1.push(diff);
            if(diff < 0){
                minl = val;
            }
        }
    }
    
    void pop() {
        if(s1.empty()) return;
        long long diff = s1.top();
        s1.pop();
        if(diff < 0) minl = minl - diff;
    }
    
    int top() {
        if(s1.empty()) return 0;
        long long diff = s1.top();
        if(diff >= 0) return minl+diff;
        else return minl;
    }
    
    int getMin() {
        return minl;
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