class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(); 
        int n = heights[0].size(); 
        vector<vector<int>> pa(m,vector<int>(n,0));
        vector<vector<int>> at(m,vector<int>(n,0));
        queue<pair<int,int>> qp; 
        queue<pair<int,int>> qa; 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0){
                    pa[i][j] = 1; 
                    qp.push({i,j});
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == m-1  || j == n-1){
                    at[i][j] = 1; 
                    qa.push({i,j});
                }
            }
        }
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        auto bfs =[&](vector<vector<int>>&vis, queue<pair<int,int>> q){
            while(!q.empty()){
                auto [x,y] = q.front(); 
                q.pop(); 
                for(int i = 0; i < 4; i++){
                    int nx = dx[i] + x; 
                    int ny = dy[i] + y; 
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                        if(heights[nx][ny] >= heights[x][y] && !vis[nx][ny]){
                            vis[nx][ny] =  1; 
                            q.push({nx,ny});
                        }
                    }
                }
            }
        };
        bfs(pa,qp);
        bfs(at,qa);
        vector<vector<int>> ans; 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pa[i][j] && at[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans; 
    }
};
