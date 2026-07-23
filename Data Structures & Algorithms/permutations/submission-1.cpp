class Solution {
public:

    void f(int i,vector<int>nums,vector<vector<int>>&ans){
        if(i==nums.size())ans.push_back(nums);
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            f(i+1,nums,ans);
            swap(nums[j],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        f(0,nums,ans);
        return ans;
    }
};
