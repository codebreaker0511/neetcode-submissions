class Solution {
public:
    //minimum spannning trees??
    //kruskal or prim?? 
    struct DSU{
        vector<int> parent, sz; 
        DSU(int n){
            parent.assign(n,-1);
            sz.assign(n,1);
            for(int i = 0; i < n; i++){
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
            if(a != b){
                if(sz[a] < sz[b]) swap(a,b);
                sz[a] += sz[b];
                parent[b] = a; 
            }
        }
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<tuple<int,int,int>> edges;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int x1 = points[i][0]; int x2 = points[j][0];
                int y1 = points[i][1]; int y2 = points[j][1];
                int dis = abs(x1-x2) + abs(y1-y2);
                edges.push_back({dis,i,j});
            }
        }
        sort(edges.begin(), edges.end());
        DSU dsu(n);
        int ans = 0; 
        for(auto [wt,u,v]: edges){
            if(dsu.find(u) != dsu.find(v)){
                dsu.unite(u,v);
                ans += wt; 
            }
        }
        return ans; 
    }
};
