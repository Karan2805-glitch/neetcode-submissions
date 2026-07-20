class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
    vector<pair<int,int>> pos_and_speed;

    for(int i=0;i<n;i++){
        pos_and_speed.push_back({position[i],speed[i]});
    }

    sort(pos_and_speed.begin(),pos_and_speed.end(),greater<>());

    int count = 0;

    vector<double> time_taken(n);

    for(int i=0;i<n;i++){
        time_taken[i] = (double)(target - pos_and_speed[i].first)/pos_and_speed[i].second;
    }

    stack<double> st;
    st.push(time_taken[0]);

    for(int i=1;i<n;i++){
        if(time_taken[i] > st.top()){
            st.push(time_taken[i]);
        }
    }

    return st.size();
    }
};
