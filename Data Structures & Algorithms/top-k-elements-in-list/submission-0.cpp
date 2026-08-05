class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> v; 
        map<int,int> mp; 
        for(int i = 0; i < nums.size(); i++) mp[nums[i]]++; 
        for(auto [x,y]: mp){
            v.push_back({y,x});
        }
        sort(v.rbegin(), v.rend());
        vector<int> ans; 
        for(int i = 0; i < k; i++) ans.push_back(v[i].second);
        return ans; 
    }
};
