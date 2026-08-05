class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // time complexity of this approach is O(n).. 
        // and space complexity is  O(n).. optimal approach..
        int n = nums.size(); 
        int l = 0; int r = n-1; 
        vector<pair<int,int>> v; 
        for(int i = 0; i < n; i++){
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end()); 
        while(l < r){
            int cur = v[l].first + v[r].first;  
            if(cur > target){
                r--; 
            }
            else if(cur < target) l++; 
            else{
                vector<int> ans = {v[l].second, v[r].second};
                sort(ans.begin(), ans.end());
                return ans; 
            }
        }
        return {-1};
    }
};
