class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxo=nums[0];
        for(int i=0;i<n;i++){
            if(i>maxo)return false;
            maxo=max(maxo,i+nums[i]);
        }
        return true;
    }
};
