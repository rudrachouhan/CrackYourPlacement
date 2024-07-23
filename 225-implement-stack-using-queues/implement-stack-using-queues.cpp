class MyStack {
public:
    queue<int> q;
    int count;
    MyStack() {
        count = 0;
    }
    
    void push(int x) {
        int k = 0;
        if(q.size()==0)
        q.push(x);
        else{
            q.push(x);
        while(k<count){
            int ans = q.front();
            q.pop();
            q.push(ans);
            k++;
        }}
        count++;
    }
    
    int pop() {
        if(q.size()==0)
        return -1;
        else{
        int ans = q.front();
        q.pop();
        count--;
        return ans;
        }
        return -1;
    }
    
    int top() {
        if(q.size()==0)
        return -1;
        return q.front();
    }
    
    bool empty() {
       if(q.size()==0)
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