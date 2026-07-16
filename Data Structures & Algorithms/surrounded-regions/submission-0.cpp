class Solution {
public:

    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>& vis){
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 
                && ncol < m && board[nrow][ncol] == 'O' 
                && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            } 
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m =board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i = 0; i< n; i++){
            if(board[i][0] == 'O') {
                vis[i][0] = 1;
                dfs(i,0,board,vis);
            }
            if(board[i][m-1] == 'O') {
                vis[i][m-1] = 1;
                dfs(i,m-1,board,vis);
            }
        }
        for(int j = 0; j< m; j++){
            if(board[0][j] == 'O') {
                vis[0][j] = 1;
                dfs(0,j,board,vis);
            }
            if(board[n-1][j] == 'O') {
                vis[n-1][j] = 1;
                dfs(n-1,j,board,vis);
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
