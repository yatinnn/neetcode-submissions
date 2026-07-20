class Solution {
public:

    void f(int i,vector<vector<int>>&ans,vector<int>temp,vector<int>&candidates,int target){
        if(target==0){
            ans.push_back(temp);
            return ;
        }
        for(int ind=i;ind<candidates.size();ind++){
            if(ind!=i && candidates[ind]==candidates[ind-1])continue;
            if(candidates[ind]<=target){
                temp.push_back(candidates[ind]);
                f(ind+1,ans,temp,candidates,target-candidates[ind]);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        f(0,ans,temp,candidates,target);
        return ans;
    }
};
