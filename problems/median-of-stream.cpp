class MedianFinder {
public:
    /** initialize your data structure here. */
    
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int> > hi;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lo.push(num);
        
        hi.push(lo.top());
        lo.pop();
        
        if(hi.size() > lo.size()){
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
       if((lo.size() + hi.size()) & 1){
           return lo.top();
       }
        
        return ((lo.top() + hi.top()) * 1.0 ) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */