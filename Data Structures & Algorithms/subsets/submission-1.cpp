class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
     vector<vector<int>>ans;
     vector<int>subset;
     sort(nums.begin(),nums.end());
     f(0,nums,subset,ans);
     return ans;
    }
    void f(int i,vector<int>nums,vector<int>& subset, vector<vector<int>>&ans){
        if(i>=nums.size()){
            return ans.push_back(subset);
        }
        subset.push_back(nums[i]);
        f(i+1,nums,subset,ans);
        subset.pop_back();
        f(i+1,nums,subset,ans);

    }
};
