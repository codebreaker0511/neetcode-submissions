class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(); 
        int l = 0; int r = n-1; 
        int ans = 0; 
        while(l < r){
            int cur = min(heights[l], heights[r])*(r - l);
            if(heights[l] > heights[r]) r--; 
            else l++; 
            ans = max(cur, ans);
        }
        return ans; 
    }
};
