class Solution {
public:
    int convertString(string s){
    int val = 0;
    bool neg = false;
    if(s[0] == '-'){
        for(int i=1;i<s.size();i++){
            val = val*10 + (s[i] - '0'); 
        }
        return val*-1;
    }
    else{
        for(char ch : s){
            val = val*10 + (ch - '0'); 
        }
        return val;
    }
}
int evalRPN(vector<string>& tokens){
    stack<int> st;
    int res = 0;
    for(string s : tokens){
        if(s == "+" || s == "-" || s == "*" || s == "/"){
            int v1 = st.top();
            st.pop();
            int v2 = st.top();
            st.pop();
            if(s == "+")st.push(v2+v1);
            else if(s == "-")st.push(v2-v1);
            else if(s == "*")st.push(v1*v2);
            else if(s == "/")st.push(v2/v1);
        }
        else{
            int val = convertString(s);
            st.push(val);
        }
    }
    return st.top();
}
};