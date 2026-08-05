class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //without using the div op means we should use prefix and suf..
        int n = nums.size();  
        vector<int> pref(n, 0);
        vector<int> suf(n,0);
        pref[0] = nums[0];
        suf[n-1] = nums[n-1];
        for(int i = 1; i < n; i++) pref[i] = pref[i-1]*nums[i];
        for(int i = n-2; i >= 0; i--) suf[i] = suf[i+1]*nums[i];
        vector<int> ans; 
        for(int i = 0; i < n; i++){
            if(i == 0) {
                ans.push_back(suf[i+1]);
                continue; 
            }
            if(i == n-1){
                ans.push_back(pref[n-2]);
                continue; 
            }
        
            //now i is between 0 and n - 1.. 
            ans.push_back(pref[i-1]*suf[i+1]);
        }
        return ans; 
    }
};
