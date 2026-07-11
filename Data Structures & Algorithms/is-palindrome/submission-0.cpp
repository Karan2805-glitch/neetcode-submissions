class Solution {
public:
    bool isPalindrome(string s) {
        string ns;
    for(char ch : s){
        if(ch>='a' && ch<='z')ns+=ch;
        else if(ch>='A' && ch<='Z')ns+=tolower(ch);
        else if(ch>='0' && ch<='9')ns+=ch;
        else continue;
    }

    int n = ns.size();
    int i = 0;
    int j = n-1;
    while(i<j){
        if(ns[i] != ns[j])return false;
        i++;
        j--;
    }
    return true;
    }
};
