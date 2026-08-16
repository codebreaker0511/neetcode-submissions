class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(); 
        if(n == 0) return 0; 
        map<char, int> mp; 
        int l = 0; 
        int ans = 1; 
        for(int r = 0; r < n; r++){
            mp[s[r]]++; 
            while(mp[s[r]] > 1){
                mp[s[l]]--; 
                l++; 
            }
            ans = max(r - l + 1, ans);
        }
        return ans; 
    }
};
