class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
         vector<vector<int>>ans;
     vector<int>subset;
     f(0,nums,subset,ans,target);
     return ans;
    }
     void f(int i,vector<int>nums,vector<int>& subset, vector<vector<int>>&ans,int target){
        if(target==0){
            return ans.push_back(subset);
        }
        if(i>=nums.size() || target<0)return ;

        subset.push_back(nums[i]);
        f(i,nums,subset,ans,target-nums[i]);
        subset.pop_back();
        f(i+1,nums,subset,ans,target);

    }
};
