class Solution {
public:
    bool validTree(int k, vector<vector<int>>& edges) {
            int n = edges.size();
            if(n != k-1) return false;

            vector<vector<int>>adjl(k);
            for(auto it : edges){
                adjl[it[0]].push_back(it[1]);
                adjl[it[1]].push_back(it[0]);
            }

            vector<int>vis(k,0);
            queue<pair<int,int>>q;
            q.push({0,-1});
            while(!q.empty()){
                int node = q.front().first;
                int prev = q.front().second;
                vis[node]=1;
                q.pop();
                for(auto it : adjl[node]){
                    if(!vis[it]){
                    q.push({it,node});
                    }
                    else {
                        if(prev!=it)return false;
                        }
                }
            }
            for (int i = 0; i < k; i++) {
            if (!vis[i]) return false;
             }

            return true;
    }
};
