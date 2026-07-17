class MinStack {
public:
vector<int> min_values;
        stack<int> st;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(min_values.empty())min_values.push_back(val);
        else{
            int min_val = min(min_values.back(),val);
            min_values.push_back(min_val);
        }
    }
    
    void pop() {
        st.pop();
        min_values.pop_back();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_values.back();
    }
};
