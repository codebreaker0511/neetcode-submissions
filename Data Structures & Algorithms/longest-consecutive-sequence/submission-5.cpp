class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st; 
        for(auto x: nums) st.insert(x);
        int longest = 0; 
        for(auto x: st){
            if(st.find(x - 1) == st.end()){
                int length = 1; 
                while(st.find(x + length) != st.end()){
                    length++; 
                }
                longest = max(length, longest);
            }
        }
        return longest; 
    }
};
