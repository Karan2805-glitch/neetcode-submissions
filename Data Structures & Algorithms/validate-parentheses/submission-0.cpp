class Solution {
public:
    bool isValid(string s) {
        int n = s.size();

    stack<char> st;
    int r = 0;

    while(r<n){
        if(s[r] == '(' || s[r] == '{' || s[r] == '['){
            st.push(s[r]);
            r++;
        }
        else{
            if(s[r] == ')'){
                if(st.empty() || st.top() != '(')return false;
                st.pop();
                r++;
            }
            else if(s[r] == '}'){
                if(st.empty() || st.top() != '{')return false;
                st.pop();
                r++;
            }
            else if(s[r] == ']'){
                if(st.empty() || st.top() != '[')return false;
                st.pop();
                r++;
            }
        }
    }

    if(!st.empty())return false;
    return true;
    }
};
