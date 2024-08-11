class MyStack {
public:
    int N;
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        N=0;
    }
    
    void push(int x) {
        q2.push(x);
        N++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
    }
    
    int pop() {
        int val=q1.front();
        q1.pop();
        N--;
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return N==0;
    }
};
