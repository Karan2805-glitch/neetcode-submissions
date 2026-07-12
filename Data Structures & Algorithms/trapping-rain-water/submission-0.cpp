class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
    stack<int> st;
    int water = 0;

    for(int i=0;i<n;i++){
        if(!st.empty() && height[i] > height[st.top()]){
            while(!st.empty() && height[i] > height[st.top()]){
                int bottom = st.top();
                st.pop();

                if(st.empty())break;

                int width = i - st.top() - 1;
                int bounded_height = min(height[st.top()],height[i]) - height[bottom];
                water+= width*bounded_height;
            }
        }
        st.push(i);
    }

    return water;
    }
};
