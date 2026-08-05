class Solution {
public:

    string encode(vector<string>& strs) {
        string encod = "";
        int n = strs.size();
        for(int i = 0; i < n; i++){
            string cur = strs[i];
            int len = cur.size(); 
            encod += to_string(len) + "#" + cur; 
        } 
        return encod; 
    }

    vector<string> decode(string s) {
        int n = s.size(); 
        vector<string> ans; 
        for(int i = 0; i < n; ){
            int len = 0; 
            while (s[i] != '#'){
                len = (s[i]-'0') + len*10; 
                i++; 
            }
            string cur = "";
            i++; 
            cur += s.substr(i,len);
            ans.push_back(cur);
            i += len;
        }
        return ans; 
    }
};
