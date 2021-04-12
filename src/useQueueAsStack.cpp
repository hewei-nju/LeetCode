class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (q1.size() <= 1) {
            while(!q2.empty()) {
                int num = q2.front();
                q2.pop();
                q1.push(num);
            }
            q2.push(x);
        } else {
            while(!q1.empty()) {
                int num = q2.front();
                q2.pop();
                q2.push(num);
            }
            q1.push(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (q2.size() == 1) {
            int num = q2.front();
            q2.pop();
            return num;
        } else {
            int num = q1.front();
            q1.pop();
            return num;
        }
    }
    
    /** Get the top element. */
    int top() {
        if (q1.size() == 1) {
            return q1.front();
        } else {
            return q2.front();
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.emtpy() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */