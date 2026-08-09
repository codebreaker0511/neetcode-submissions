class Solution {
public:
    //dijsktra??
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0]; int v = times[i][1]; 
            int wt = times[i][2];
            //build the directed graph with wt.. 
            adj[u].push_back({v,wt});
        }
        //initialize a min heap.. 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq; 
        vector<int> dis(n + 1, 1e9);
        dis[k] = 0; //starting from k.. 
        pq.push({0,k});
        while(!pq.empty()){
            auto [ds,node] = pq.top(); 
            pq.pop(); 
            if(ds > dis[node]) continue; 
            for(auto it: adj[node]){
                int to = it.first;
                int cst = it.second; 
                if(dis[to] > cst + ds){
                    dis[to] = cst + ds; 
                    pq.push({cst+ds, to});
                }
            }
        }
        int ans = -1; 
        for(int i = 1; i <= n; i++){
            if(dis[i] == 1e9) return -1; 
            ans = max(ans, dis[i]);
        }

        return ans; 
    }
};
