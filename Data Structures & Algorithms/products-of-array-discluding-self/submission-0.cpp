class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
    vector<int> pre_prod(n);
    vector<int> suff_prod(n);
    pre_prod[0]=1;
    suff_prod[n-1]=1;
    for(int i=1;i<n;i++){
        pre_prod[i] = pre_prod[i-1]*nums[i-1];
    }
    for(int i=n-2;i>=0;i--){
        suff_prod[i] = suff_prod[i+1]*nums[i+1];
    }

    vector<int> res(n);
    res[0] = suff_prod[0];
    res[n-1] = pre_prod[n-1];

    for(int i=1;i<=n-2;i++){
        res[i] = pre_prod[i]*suff_prod[i];
    }

    return res;
    }
};
