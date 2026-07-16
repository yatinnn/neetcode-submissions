class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>timeStore(n,vector<int>(m,2147483647));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    q.push({{i,j},0});
                    timeStore[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m ){
                    if(grid[nrow][ncol] == -1){
                    timeStore[nrow][ncol]=-1;
                    }
                    else {
                            int minTime = timeStore[nrow][ncol];
                            minTime = min(minTime , time + 1);
                            if(minTime == timeStore[nrow][ncol])continue;
                            q.push({{nrow,ncol},minTime});
                            timeStore[nrow][ncol] = minTime;

                    }
                }
            }
        }
            grid=timeStore;
    }
};
