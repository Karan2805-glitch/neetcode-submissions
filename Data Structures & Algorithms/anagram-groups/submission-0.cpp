class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
    unordered_map<string,vector<string>> mp;

    for(string s : strs){
        vector<int> freq(26,0);
        for(char ch : s){
            freq[ch-'a']++;
        }
        string sm = "";

        for(int i=0;i<26;i++){
            sm+=to_string(freq[i])+"#";
        }

        mp[sm].push_back(s);
    }

    vector<vector<string>> res;

    for(auto& g : mp){
        res.push_back(g.second);
    }

    return res;
    }
};
