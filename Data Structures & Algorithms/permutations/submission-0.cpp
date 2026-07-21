class Solution {
public:

    void f(int i,vector<int>nums,vector<vector<int>>& ans){
        if(i==nums.size())return ans.push_back(nums);
        for(int ind=i;ind<nums.size();ind++){
            swap(nums[i],nums[ind]);
            f(i+1,nums,ans);
            swap(nums[i],nums[ind]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        f(0,nums,ans);
        return ans;
    }
};
