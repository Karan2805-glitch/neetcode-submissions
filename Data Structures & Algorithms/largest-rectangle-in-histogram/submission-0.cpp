class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();

    vector<int> psi(n),nsi(n);
    stack<int> st;

    for(int i=0;i<n;i++){
        while(!st.empty() && heights[st.top()] >= heights[i])st.pop();

        psi[i] = st.empty()?-1:st.top();
        st.push(i);
    }

    while(!st.empty())st.pop();

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && heights[st.top()] >= heights[i])st.pop();

        nsi[i] = st.empty()?n:st.top();
        st.push(i);
    }

    int max_area = 0;
    for(int i=0;i<n;i++){
        int len = nsi[i] - psi[i] - 1;
        max_area = max(max_area,heights[i]*len);
    }

    return max_area;
    }
};
