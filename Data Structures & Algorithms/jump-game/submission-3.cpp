class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        if(nums[0]==0 && n==1)return 1;
        return f(0,n,nums,dp);
    }

    bool f(int i,int n,vector<int>&nums,vector<int>&dp){
        if(i>=n-1)return 1;
        if(nums[i]==0)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=0;
        for(int ind=0;ind<nums[i];ind++){
        ans=ans||f(i+ind+1,n,nums,dp);
        }
        return dp[i]=ans;
    }
};
