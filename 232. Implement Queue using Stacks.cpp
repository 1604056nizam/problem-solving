class MyQueue {
public:
    stack<int> st;
    stack<int> helperStack;

    MyQueue() {}

    void push(int x) { 
        this->st.push(x); 
    }

    int peekOrPop(bool isPeekOperation) {
        int temp, result;
        while (this->st.size() != 1) {
            temp = this->st.top();
            this->st.pop();
            this->helperStack.push(temp);
        }

        result = this->st.top();
        this->st.pop();

        if (isPeekOperation) {
            this->helperStack.push(result);
        }
        

        while (!this->helperStack.empty()) {
            temp = this->helperStack.top();
            this->helperStack.pop();
            this->st.push(temp);
        }

        return result;
    }

    int pop() {
        return peekOrPop(false);
    }

    int peek() {
        return peekOrPop(true);
    }

    bool empty() { 
        return this->st.size() == 0; 
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