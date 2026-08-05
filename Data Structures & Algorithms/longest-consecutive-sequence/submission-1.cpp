class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }
        int ans = 0;
        vector<int> v;
        for(auto x: st){
            v.push_back(x);
        }
        int s = v.size();
        int cur = 1;
        for(int i = 1; i < s; i++){
            if(v[i] == v[i-1] + 1) cur++;
            else{
                ans = max(cur, ans);
                cur = 1;
            }
        }
        if(n == 0) return 0;
        ans = max(cur, ans);
        return ans;
    }
};
