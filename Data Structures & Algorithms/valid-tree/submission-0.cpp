class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis; 
    bool dfs(int start, int par){
        vis[start] = 1; 
        for(auto it: adj[start]){
            if(!vis[it]){
                if(dfs(it, start)) return true; 
            }
            else if(it != par) return true; 
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false; 
        adj.resize(n,{});
        vis.resize(n,0);
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        if(dfs(0,-1)) return false;
        for(int i = 0; i < n; i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};
