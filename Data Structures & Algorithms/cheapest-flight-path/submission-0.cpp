class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,1e9);
        dist[src]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{src,0}});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stops>k)continue;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edgw=it.second;
                
                if(cost+edgw<dist[adjnode]){
                    dist[adjnode]=cost+edgw;
                    pq.push({stops+1,{adjnode,dist[adjnode]}});
                }
            }
        }
        if(dist[dst]==1e9)return -1;
        return dist[dst];
    }
};
