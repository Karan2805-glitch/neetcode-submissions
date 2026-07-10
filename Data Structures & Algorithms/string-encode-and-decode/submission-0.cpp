class Solution {
   public:
    string encode(vector<string>& strs) {
        int n = strs.size();
        string es;
        for (string s : strs) {
            int l = s.size();
            es += to_string(l);
            es += '#';
            for (char ch : s) {
                es += ch;
            }
        }
        return es;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            string ns;
            int val = 0;
            while (s[i] != '#') {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            i++;
            for (int j = 0; j < val; j++) {
                ns += s[i];
                i++;
            }
            res.push_back(ns);
        }
        return res;
    }
};
