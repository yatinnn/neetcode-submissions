class Solution {
public:
    
    void f(int i,vector<int>& nums,vector<int>&temp,vector<vector<int>>&ans){
        ans.push_back(temp);
        for(int j=i;j<nums.size();j++){
            if(i!=j&&nums[j]==nums[j-1])continue;
            temp.push_back(nums[j]);
            f(j+1,nums,temp,ans);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
     vector<int>subset;
     sort(nums.begin(),nums.end());
     f(0,nums,subset,ans);
     return ans;
    }
};
