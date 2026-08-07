class Solution {
public:
    struct DSU{
        vector<int> parent, sz; 
        DSU(int n){
            parent.assign(n+1,-1);
            sz.assign(n+1,1);
            for(int i = 1; i <= n; i++){
                parent[i] = i; 
            }
        }

        int find(int v){
            if(parent[v] == v) return v; 
            return parent[v] = find(parent[v]);
        }

        void unite(int a, int b){
            a = find(a);
            b = find(b);
            if(a!=b){
                if(sz[a] < sz[b]) swap(a,b);
                parent[b] = a; 
                sz[a] += sz[b];
            }
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1; 
        DSU dsu(n);
        for(int i = 0; i < n-1; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            if(dsu.find(a) == dsu.find(b)){
                return {a,b};
            }
            dsu.unite(a,b);
        }
        return {};
    }
};
