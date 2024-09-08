class MyStack {
public:
    queue<int> q;
    queue<int> helperQ;
    MyStack() {}

    void push(int x) { this->q.push(x); }

    int removeOperation(bool isTopOperation) {
        int result, top;

        while (this->q.size() != 1) {
            top = this->q.front();
            this->q.pop();
            this->helperQ.push(top);
        }

        result = this->q.front();
        this->q.pop();

        if (isTopOperation) {
            this->helperQ.push(result);
        }

        while (!this->helperQ.empty()) {
            top = this->helperQ.front();
            this->helperQ.pop();
            this->q.push(top);
        }

        return result;
    }

    int pop() { return this->removeOperation(false); }

    int top() { return this->removeOperation(true); }

    bool empty() {
        if (this->q.size() == 0)
            return true;
        return false;
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