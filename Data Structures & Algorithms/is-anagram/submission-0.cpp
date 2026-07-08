class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.size();
    int n2 = t.size();

    if(n1!=n2)return false;

    unordered_map<char,int> mp1;
    unordered_map<char,int> mp2;

    for(int i=0;i<n1;i++)mp1[s[i]]++;
    for(int i=0;i<n2;i++)mp2[t[i]]++;

    for(char ch='a';ch<='z';ch++){
        if(mp1[ch]!=mp2[ch])return false;
    }

    return true;
    }
};
