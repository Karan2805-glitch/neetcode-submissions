class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
    unordered_map<int,vector<int>> mp;
    vector<int> res;
    for(int i=0;i<n;i++){
        if(mp.find(nums[i])!=mp.end()){
            res.push_back(mp[nums[i]][0]);
            res.push_back(i);
            break;
        }
        mp[target - nums[i]].push_back(i);
    }

    return res;
    }
};
