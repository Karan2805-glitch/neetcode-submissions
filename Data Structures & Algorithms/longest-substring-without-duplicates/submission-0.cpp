class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            int n = s.size();
        if(n==0)return 0;
    int l = 0;
    int r = 0;
    set<char> unique_chars;
    int max_window = 1;

    while(r < n){
        if(unique_chars.count(s[r])){
            char ch = s[r];
            while(l<n && s[l] != ch){
                unique_chars.erase(s[l]);
                l++;
            }
            unique_chars.erase(ch);
            l++;
        }
        unique_chars.insert(s[r]);
        max_window = max(max_window,r-l+1);
        r++;
    }
    return max_window;
    }
};
