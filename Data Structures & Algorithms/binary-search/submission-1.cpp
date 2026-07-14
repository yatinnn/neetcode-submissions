class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        while(hi>=lo){
            int mid=(hi+lo)/2;
            if(target==nums[mid])return mid;
            if(target>nums[mid])lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
};