class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(!st2.empty()){
            int del = st2.top();
            st2.pop();
            return del;
        }
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            int del = st2.top();
            st2.pop();
            return del;
        }
    }
    
    int peek() {
        if(!st2.empty()){
            return st2.top();
        }
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }
    
    bool empty() {
        if(st1.empty() && st2.empty()){
            return true;
        }
        else{
            return false;
        }
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