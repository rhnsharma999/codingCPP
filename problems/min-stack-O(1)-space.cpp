class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<long long int> s;
    long long int minElement;
    
    MinStack() {
        minElement = -1;
    }
    
    void push(int x) {
        long long int y = x;
      if(s.empty()){
          s.push(y);
          minElement = y;
      } else{
          if(y >= minElement){
              s.push(y);
          } else{
              s.push(2 * y - minElement);
              minElement = y;
          }
      }
    }
    
    void pop() {
        if(s.empty()) return;
        if(s.top() >= minElement) s.pop();
        else{
            long long int top = s.top();
            minElement = 2 * minElement - top;
            s.pop();
        }
        
    }
    
    int top() {
        if(s.empty()) return -1;
        if(s.top() >= minElement) return s.top();
        else{
            return minElement;
        }
    }
    
    int getMin() {
       return minElement;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */