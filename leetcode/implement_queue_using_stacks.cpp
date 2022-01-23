class MyQueue {
private:
    stack<int> s1, s2;
public:
    MyQueue() {
        s1 = stack<int>();
        s2 = stack<int>();
        
    }
    
    void push(int x) {
        if (s1.empty()){
            s1.push(x);
            return;
        }
        s2.push(x);
        return;
    }
    
    int pop() {
        int x = s1.top();
        s1.pop();
        if (s1.empty()){
            while (!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        return x;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */