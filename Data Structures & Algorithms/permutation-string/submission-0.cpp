class Solution {
public:
    bool checkInclusion(string s1, string s2) {
            if(s1.size() > s2.size()) return false;
    int n1 = s2.size();
    int n2 = s1.size();
    vector<vector<int>> freq1(n1,vector<int>(26,0));

    freq1[0][s2[0] - 'a']++;
    for(int i=1;i<n1;i++){
        freq1[i] = freq1[i-1];
        freq1[i][s2[i] - 'a']++;
    }

    vector<int> freq2(26,0);
    for(int i=0;i<n2;i++){
        freq2[s1[i]-'a']++;
    }

    int l = 0;
    int r = n2 - 1;

    while(r<n1){
        vector<int> temp(26);
        for(int i=0;i<26;i++){
            if(l==0){
                temp[i] = freq1[r][i];
            }
            else{
                temp[i] = freq1[r][i] - freq1[l-1][i];
            }
        }
        if(temp == freq2) return true;
        r++;
        l++;
    }

    return false;
    }
};
