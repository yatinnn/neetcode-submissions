class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+2,0);
        // return min(f(0,cost,n,dp),f(1,cost,n,dp));
        for(int ind=n-1;ind>=0;ind--){
        dp[ind]=cost[ind]+min(dp[ind+1],dp[ind+2]);
        }
        return min(dp[0],dp[1]);
    }
    
    int f(int ind,vector<int>&cost,int n,vector<int>&dp){
        if(ind>=n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        return dp[ind]=cost[ind]+min(f(ind+1,cost,n,dp),f(ind+2,cost,n,dp));
    }
};
