class Solution {
public:

    void dfs(int i,int j,int prev,vector<vector<int>>& ocean,vector<vector<int>>& heights){
        if(i >= heights.size() || i < 0 
        || j >= heights[0].size() || j < 0 
        || ocean[i][j] == 1 || heights[i][j] < prev) {
            return ;
        }
        ocean[i][j] = 1;
        dfs(i+1,j,heights[i][j],ocean,heights);
        dfs(i-1,j,heights[i][j],ocean,heights);
        dfs(i,j+1,heights[i][j],ocean,heights);
        dfs(i,j-1,heights[i][j],ocean,heights);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>atlantic(n,vector<int>(m,0));
        vector<vector<int>>pacific(n,vector<int>(m,0));

        for(int i = 0; i < m; i++){
            dfs(0,i,INT_MIN,pacific,heights);
            dfs(n-1,i,INT_MIN,atlantic,heights);
        }

        for(int i = 0; i < n; i++){
            dfs(i,0,INT_MIN,pacific,heights);
            dfs(i,m-1,INT_MIN,atlantic,heights);
        }  

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pacific[i][j] == 1 && atlantic[i][j] == 1){
                    ans.push_back({i,j});
                }
            }
        } 
        return ans;
    }
};
