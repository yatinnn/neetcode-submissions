class Solution {
public:
       void solve(int col,vector<string>&board,vector<vector<string>>&ans,
       int n,vector<int>&leftr,vector<int>&lower,vector<int>&upper){
        if(col==n)return ans.push_back(board);
           for(int row=0;row<n;row++){
               if(leftr[row]==0 && lower[row+col]==0 && upper[n-1+col-row]==0){
                   board[row][col]='Q';
                   leftr[row]=1,lower[row+col]=1,upper[n-1+col-row]=1;
                   solve(col+1,board,ans,n,leftr,lower,upper);
                   board[row][col]='.';
                   leftr[row]=0,lower[row+col]=0,upper[n-1+col-row]=0;
               }
           }
           
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n, string(n, '.'));
        vector<int>leftr(n,0),lower(2*n-1,0),upper(2*n-1,0);
        solve(0,board,ans,n,leftr,lower,upper);
        return ans;
    }
};