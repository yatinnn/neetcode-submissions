class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        int cnt = 0;
        int tm = -1;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    cnt++;
                }
                else if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;

                }
            }
        }
        
        if(cnt == 0) {
            return cnt;
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol] ){
                    if(grid[nrow][ncol] == 0){
                    continue;
                    }
                    else {

                            tm = max(tm , time + 1);
                            q.push({{nrow,ncol},time+1});
                            vis[nrow][ncol] = 1;
                            cnt--;


                    }
                }
            }
        }
        if(cnt == 0){
            return tm;
        }
        return -1;
    }
};
