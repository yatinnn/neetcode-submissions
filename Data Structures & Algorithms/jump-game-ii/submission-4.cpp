class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        int steps=0;
        int maxo=0;
        int currentend=0;
        for(int i=0;i<n-1;i++){
            maxo=max(maxo,i+nums[i]);
            if(i==currentend){
                steps++;
            currentend=maxo;
            }
        }
        return steps; 
    }
};
