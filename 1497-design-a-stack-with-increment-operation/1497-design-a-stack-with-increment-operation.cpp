class CustomStack {
public:
    vector<int>vec;
    int n;
    CustomStack(int maxSize) {
        n=maxSize;

    }
    
    void push(int x) {
        if(vec.size()<n)
            vec.push_back(x);
    }
    
    int pop() {
        if(vec.size()==0)
            return -1;
        int top = vec.back();
        vec.pop_back();
        return top;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,(int)vec.size());i++){
            vec[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */