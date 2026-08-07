class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(); 
        int l = 0; int r = n-1; 
        while(l <= r){
            int md = l + (r - l)/2;
            if(nums[md] == target){
                return md;
            }
            if(nums[md] > target){
                r = md - 1;
            }
            else{
                l = md + 1;
            }
        }
        return -1;
    }
};
