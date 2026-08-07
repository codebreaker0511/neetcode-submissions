class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int sz = edges.size(); 
        for(int i = 0; i < sz; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n,0);
        auto bfs = [&](int strt){
            vis[strt] = 1; 
            queue<int> q; 
            q.push(strt);
            while(!q.empty()){
                auto node = q.front(); 
                q.pop(); 
                for(auto it: adj[node]){
                    if(!vis[it]){
                        vis[it] = 1; 
                        q.push(it);
                    }
                }
            }
        };
        int cnt = 0; 
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                bfs(i);
                cnt++; 
            }
        }

        return cnt; 
    }
};
