class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
         vector<string> board(n, string(n, '.'));
        vector<int>left(n,0);
        vector<int>lower(2*n-1,0);
        vector<int>upper(2*n-1,0);
        f(0,left,lower,upper,board,ans,n);
        return ans;
    }

    void f(int i,vector<int>& left,vector<int>& lower,vector<int>& upper,vector<string>& board,vector<vector<string>>&ans,int n){
        if(i==n){ ans.push_back(board);
        return ;
        }
        for(int row=0;row<n;row++){
            if(left[row]==0 && lower[row+i]==0 && upper[n-1+i-row]==0 ){
                board[row][i]='Q';
                left[row]=1 , lower[row+i]=1 , upper[n-1+i-row]=1;
                f(i+1,left,lower,upper,board,ans,n);
                 board[row][i]='.';
                left[row]=0,lower[row+i]=0 ,upper[n-1+i-row]=0;

            }
        }
    }
};
