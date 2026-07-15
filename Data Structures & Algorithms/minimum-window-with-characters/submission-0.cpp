class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size();
    int n2 = t.size();

    if(n2>n1)return "";

    string res = "";
    int min_len = INT_MAX;

    unordered_map<char,int> freq1; 
    unordered_map<char,int> freq2;
    
    for(char ch : t){
        freq2[ch]++;
    }

    int required = freq2.size();
    int formed = 0;

    int l=0;
    int r=0;
    int start = l;

    while(r<n1){
        freq1[s[r]]++;
        if(freq2.count(s[r]) && freq1[s[r]] == freq2[s[r]])formed++;

        while(formed == required){
            if(min_len > r-l+1){
                start = l;
                min_len = r-l+1;
            }
            if(freq2.count(s[l]) && freq1[s[l]] == freq2[s[l]])formed--;
            freq1[s[l]]--;
            l++;
        }
        r++;
    }
    if(min_len == INT_MAX)return "";

    res = s.substr(start,min_len);
    return res;
    }
};
