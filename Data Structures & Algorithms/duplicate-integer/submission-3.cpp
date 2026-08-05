class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size(); 
        map<int,int> mp; 
        for(int i = 0; i < n; i++){
            mp[nums[i]]++; 
            if(mp[nums[i]] >= 2) return true;
        }
        return false; 
    }
};