class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(); 
        int n = board[0].size(); 
        queue<pair<int,int>> q; 
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    if(board[i][j] == 'O'){
                        q.push({i,j});
                        vis[i][j] = 1; 
                    }
                }
            }
        }
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(!q.empty()){
            int sz = q.size(); 
            for(int i = 0; i < sz; i++){
                auto [x,y] = q.front(); 
                q.pop(); 
                for(int i = 0; i < 4; i++){
                    int nx = dx[i] + x;
                    int ny = dy[i] + y; 
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                        if(!vis[nx][ny] && board[nx][ny] == 'O'){
                            q.push({nx,ny});
                            vis[nx][ny] = 1; 
                        }
                    }
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};
