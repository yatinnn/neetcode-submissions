class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(0,0,s,p,dp);
    }

    bool f(int i,int j,string s,string p,vector<vector<int>>&dp){
        int n=s.size();
        int m=p.size();
        if(j==m)return i==n;
        

        // if(j>=m)return false;
        if(dp[i][j]!=-1)return dp[i][j];
        
          bool firstMatch = (i < n && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < m && p[j + 1] == '*') {
            return dp[i][j] =
                f(i, j + 2, s, p, dp) ||              // use zero occurrence
                (firstMatch && f(i + 1, j, s, p, dp)); // use one or more
        }
         return dp[i][j] = firstMatch && f(i + 1, j + 1, s, p, dp);
    }
};
