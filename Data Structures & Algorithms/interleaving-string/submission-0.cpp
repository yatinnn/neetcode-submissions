class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int k=s3.size();
        if(n+m!=k)return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(0,0,0,s1,s2,s3,n,m,k,dp);
    }

    bool f(int i,int j,int k,string s1,string s2,string s3,int n,int m,int l,vector<vector<int>>&dp){
        if(k>=l)return 1;
        
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s3[k] && s2[j]==s3[k])return dp[i][j]=f(i+1,j,k+1,s1,s2,s3,n,m,l,dp)||f(i,j+1,k+1,s1,s2,s3,n,m,l,dp);
        if(s1[i]==s3[k])return dp[i][j]=f(i+1,j,k+1,s1,s2,s3,n,m,l,dp);
        if(s2[j]==s3[k])return dp[i][j]= f(i,j+1,k+1,s1,s2,s3,n,m,l,dp);
        return false;

    }
};
