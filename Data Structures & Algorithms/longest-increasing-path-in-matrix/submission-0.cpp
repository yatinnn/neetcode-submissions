class Solution {
public:
vector<vector<int>> directions = {{-1, 0}, {1, 0},
                                      {0, -1}, {0, 1}};

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        if(n==1 && m==1)return 1;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int tmp=f(i,j,matrix,dp,n,m,-1);
                if(tmp>ans)ans=tmp;
            }
        }
        return ans;
    }

    int f(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp,int n,int m,int pre){
        if(i<0 || i>=n || j<0 || j>=m || matrix[i][j]<=pre)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=1;
        for(auto it:directions){
            int temp=1+f(i+it[0],j+it[1],matrix,dp,n,m,matrix[i][j]);
            if(temp>ans)ans=temp;
        }
        return dp[i][j]=ans;
        
    }
};
