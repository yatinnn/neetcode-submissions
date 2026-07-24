class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(auto it:intervals){
            int start=it[0];
            int end=it[1];

            if(start<=ans.back()[1]){
                ans.back()[1]=max(it[1],ans.back()[1]);
            }
            else {
                ans.push_back({start,end});
            }
        }
        return ans;
    }
};
