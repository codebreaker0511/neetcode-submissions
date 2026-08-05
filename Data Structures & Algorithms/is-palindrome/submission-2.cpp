class Solution {
public:
    bool isPalindrome(string s) {
        string t = ""; 
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(isalnum(s[i])) t += tolower(s[i]);
        }
        int sz = t.size();
        int l = 0; int r = sz - 1;
        while(l <= r){
            if(t[l] != t[r]) return false;
            else{
                l++; r--;
            }
        }
        return true;
    }
};
