class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
    sort(nums.begin(),nums.end());
    set<vector<int>> res;
    
    for(int i=0;i<n-2;i++){
        int target = -nums[i];
        int l = i+1;
        int r = n-1;
        while(l<r){
            int sum = nums[l]+nums[r];
            if(sum == target){
                res.insert({nums[i],nums[l],nums[r]});
                l++;
                r--;
            }
            else if(sum > target){
                r--;
            }
            else{
                l++;
            }
        }
    }


    vector<vector<int>> fin_res(res.begin(),res.end());

    return fin_res;
    }
};
