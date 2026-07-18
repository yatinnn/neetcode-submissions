class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int>dist(n+1,1e9);
        queue<pair<int,int>>q;
        dist[k]=0;
        q.push({k,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.first;
            int time=it.second;
            for(auto nei:adj[node]){
                int totalTime=nei.second + time;
                if(totalTime<dist[nei.first]){
                    dist[nei.first]=totalTime;
                    q.push({nei.first,totalTime});
                }
            }
        }
            int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }
        if(ans==1e9)return -1;
        return ans;
    }
};
