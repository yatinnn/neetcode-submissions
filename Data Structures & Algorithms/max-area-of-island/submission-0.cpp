class Solution {
public:

     int dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid,int drow[],int dcol[],int n,int m){
        queue<pair<int,int>>q;
        int ans=1;
        q.push({i,j});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                    ans++;
                }
            }
        }
        return ans;
        
    }

    int numIslands(vector<vector<int>>& grid) {
         int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    if(!vis[i][j] && grid[i][j]==1){
                        vis[i][j]=1;
                        cnt=max(cnt,dfs(i,j,vis,grid,drow,dcol,n,m));
                    }
            }
        }
        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        return numIslands(grid);
    }
};
