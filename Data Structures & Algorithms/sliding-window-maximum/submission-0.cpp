class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

    unordered_map<int,int> freq;
    set<int> numbers;

    for(int i=0;i<k;i++){
        freq[nums[i]]++;
        numbers.insert(nums[i]);
    }

    int l = 0;
    int r = k;

    vector<int> res;
    res.push_back(*numbers.rbegin());

    while(r<n){
        freq[nums[l]]--;
        if(freq[nums[l]] == 0){
            numbers.erase(nums[l]);
        }
        l++;
        freq[nums[r]]++;
        numbers.insert(nums[r]);
        res.push_back(*numbers.rbegin());
        r++;
    }

    return res;
    }
};
