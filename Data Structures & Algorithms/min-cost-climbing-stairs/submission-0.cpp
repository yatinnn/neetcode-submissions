class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(f(0,cost,n,dp),f(1,cost,n,dp));
    }
    int f(int ind,vector<int>&cost,int n,vector<int>&dp){
        if(ind>=n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        return dp[ind]=cost[ind]+min(f(ind+1,cost,n,dp),f(ind+2,cost,n,dp));
    }
};
