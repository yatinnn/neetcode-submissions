class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int prev=intervals[0][1];

        for(int i=1;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];

            if(prev<=start){
                prev=end;
            }
            else {
                ans++;
                prev=min(end,prev);
            }
        }
        return ans;
    }
};
