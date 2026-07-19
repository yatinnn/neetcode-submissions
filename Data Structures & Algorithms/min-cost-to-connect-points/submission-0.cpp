class Solution {
public:
    int par[1001]; 
    int find(int a){ 
        if(par[a] < 0)
            return a;   
        return par[a] = find(par[a]); 
    }
    void Union(int a, int b){
        par[a] = b; 
    }
    int minCostConnectPoints(vector<vector<int>>& arr) {
        int n = arr.size(); 
        for(int i = 0; i < n; i++) par[i] = -1;
        vector<pair<int, pair<int, int>>> adj; //{weight, {i, j}}
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int weight = abs(arr[i][0] - arr[j][0]) + abs(arr[i][1] - arr[j][1]);//manhattan distance
                adj.push_back({weight, {i, j}});       
            }
        }
        sort(adj.begin(), adj.end());
        int sum = 0; 
        for(int i = 0; i < adj.size(); i++){
            int a = find(adj[i].second.first);
            int b = find(adj[i].second.second); 
            if(a != b){ // if both parents are not same then add weight 
                sum += adj[i].first;
                Union(a, b); // now merge them
            }
        }      
        return sum; 
    }
};
// 1) If we consider every point as a node and manhattan distance between them as edge weight, 
// 2) then this question is nothing minimum spanning tree.
// 3) What is minimum spanning tree? 
// 4) We have to remove some of the edges so that graph is still connected & having minimum weight.