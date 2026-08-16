class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq; 
        for(auto point: points){
            int x = point[0]; int y = point[1]; 
            int dis = x*x + y*y; 
            pq.push({dis, {x,y}});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans; 
        while(!pq.empty()){
            auto [dis, point] = pq.top(); 
            pq.pop();
            int x = point.first; 
            int y = point.second; 
            ans.push_back({x,y});
        }
        return ans; 
    }
};
