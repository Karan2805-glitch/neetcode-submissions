class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> vis;
        for (int i = 0; i < n; i++) {
            if (vis.find(nums[i]) != vis.end())
                return true;
            vis.insert(nums[i]);
        }
        return false;
    }
};