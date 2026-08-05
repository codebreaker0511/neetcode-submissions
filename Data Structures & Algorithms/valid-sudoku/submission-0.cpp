class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //row check // 
        for(int i = 0; i < 9; i++){
            map<int,int> mp; 
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    mp[board[i][j] - '0']++; 
                    if(mp[board[i][j] - '0'] >= 2) return false; 
                }
            }
        }


        //col check // 
        for(int j = 0; j < 9; j++){
            map<int,int> mp; 
            for(int i = 0; i < 9; i++){
                if(board[i][j] != '.'){
                    mp[board[i][j] - '0']++; 
                    if(mp[board[i][j] - '0'] >= 2) return false; 
                }
            }
        }


        //grid check // 
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                map<int,int> mp;
                int r = i; int c = j; 
                for(int a = r; a < r + 3; a++){
                    for(int b = c; b < c + 3; b++){
                        if(board[a][b] != '.'){
                            mp[board[a][b] - '0']++; 
                            if(mp[board[a][b] - '0'] >= 2) return false; 
                        }
                    }
                }
            }
        }


        return true; 
    }
};
