class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
            int n = nums.size();
        if(n==0)return 0;
    unordered_set<int> seq;
    int max_seq = 1;

    for(int x : nums){
        seq.insert(x);
    }

    
    for(int x : seq){
        if(!seq.count(x-1)){
            int v = x;
            int count = 0;
            while(seq.count(v)){
                v++;
                count++;
            }
            max_seq = max(max_seq,count);
        }
    }

    return max_seq;
    }
};
