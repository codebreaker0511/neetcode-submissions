class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        int l = 0; int r = n-1; 
        while(l < r){
            int cur = v[l].first + v[r].first;
            if(cur < target){
                l++;
            }
            else if(cur > target){
                r--;
            }
            else{
                return {min(v[r].second, v[l].second), 
                        max(v[r].second, v[l].second)};
            }
        }
    }
};
