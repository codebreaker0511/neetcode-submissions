class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // vector<pair<string,string>> v; 
        // int n = strs.size(); 
        // for(int i = 0; i < n; i++){
        //     string cur = strs[i];
        //     sort(cur.begin(), cur.end()); 
        //     v.push_back({cur, strs[i]});
        // } 
        // sort(v.begin(), v.end());
        // vector<vector<string>> ans; 
        // for(int i = 0; i < n; ){
        //     vector<string> cur; 
        //     cur.push_back(v[i].second);
        //     while(i + 1 < n && v[i].first == v[i + 1].first){
        //         cur.push_back(v[i+1].second);
        //         i++; 
        //     }
        //     ans.push_back(cur); 
        //     i++; 
        // }
        // return ans; 

        unordered_map<string, vector<string>> mp; 
        int n = strs.size(); 
        for(int i = 0; i < n; i++){
            string cur = strs[i];
            sort(cur.begin(), cur.end());
            mp[cur].push_back(strs[i]);
        }
        vector<vector<string>> ans; 
        for(auto &it: mp){
            ans.push_back(it.second);
        }
        return ans; 
    }
};
