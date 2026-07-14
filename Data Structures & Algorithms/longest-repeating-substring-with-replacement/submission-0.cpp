class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
    unordered_map<char,int> freq;
    unordered_set<char> unique_chars;

    for(int i=0;i<n;i++){
        freq[s[i]]++;
        unique_chars.insert(s[i]);
    }

    int max_length = 0;

    for(auto c: unique_chars){
        int l = 0;
        int r = 0;
        int count = 0;

        while(r<n){
            if(s[r] != c){
                count++;
            }

            while(count>k){
                if(s[l] != c){
                    count--;
                }
                l++;
            }

            max_length = max(max_length,r-l+1);
            r++;
        }
    }

    return max_length;
    }
};
