class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
    unordered_map<int,int> freq;

    for(int i=0;i<n;i++){
        freq[nums[i]]++;
    }

    vector<pair<int,int>> sort_freq;
    for(auto& p : freq){
        sort_freq.push_back({p.first,p.second});
    }

    sort(sort_freq.begin(),sort_freq.end(),[](const pair<int,int> &a ,const pair<int,int> &b){
        if(a.second == b.second)return a.first < b.first;
        return a.second > b.second;
    });

    vector<int> res;
    for(int i=0;i<k;i++){
        res.push_back(sort_freq[i].first);
    }

    return res;
    }
};
