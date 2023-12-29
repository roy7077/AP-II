/*------------------Method-1------------*/
class MyQueue {
    public:
    stack<int> st1,st2;
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        
        int temp=st2.top();
        st2.pop();
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return temp;
    }
    
    int peek() {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        
        int temp=st2.top();
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        
        return temp;
    }
    
    bool empty() {
        
        return st1.empty();
    }
};

/*------------------Method-2------------*/
class MyQueue {
    stack<int> s1;
    stack<int> s2;
    public:
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        
        
    }
    
    int pop() {
        int ans=s1.top();
        s1.pop();
        return ans;
        
    }
    
    int peek() {
        return s1.top();
        
    }
    
    bool empty() {
        if(s1.empty()){
            return 1;
        } return 0;
    }
};