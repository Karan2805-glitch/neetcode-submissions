class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
    stack<int> st;
    vector<int> res(n);

    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            res[i] = 0;
            st.push(i);
        }
        else{
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
                st.pop();
            }
            if(st.empty()){
                res[i] = 0;;
                st.push(i);
            }
            else{
                res[i] = st.top() - i;
                st.push(i);
            }
        }
    }

    return res;
    }
};
