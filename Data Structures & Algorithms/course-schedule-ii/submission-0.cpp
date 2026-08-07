class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses; 
        vector<vector<int>> adj(n);
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0]; 
            int v = prerequisites[i][1];
            adj[v].push_back(u); // v is a prereq of u...
        }

        vector<int> inDeg(n);
        for(int i = 0; i < n; i++){
            for(auto it: adj[i]){
                inDeg[it]++; 
            }
        }
        queue<int> q; 
        int cnt = 0; 
        for(int i = 0; i < n; i++){
            if(inDeg[i] == 0) q.push(i); // start with this order... 
        }
        vector<int> order; 
        while(!q.empty()){
            auto node = q.front(); 
            q.pop(); 
            cnt++; 
            order.push_back(node);
            for(auto it: adj[node]){
                inDeg[it]--;
                if(inDeg[it] == 0){
                    q.push(it);
                }
            }
        }
        if(cnt == n) return order; 
        return {};
    }
};
