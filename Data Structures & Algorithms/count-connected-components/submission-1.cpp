class UnionFind{
    vector<int>parent;
    vector<int>size;
    public:
            UnionFind(int n){
                parent.resize(n);
                size.resize(n);
                for(int i=0;i<n;i++){
                    parent[i]=i;
                    size[i]=1;

                }
            }

            int find(int x){
                if(x==parent[x])return x;
                // return parent[x]=find(parent[x]);
                return find(parent[x]);
            }

            bool Union(int u,int v){
                int pu=find(u);
                int pv=find(v);
                if(pu==pv)return false;
                if(pu<pv){
                    parent[pu]=pv;
                    size[pv]+=size[pu];
                }
                else{
                    parent[pv]=pu;
                    size[pu]+=size[pv];
                }
                return true;
            }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
         int diff=0;
        UnionFind uf(n+1);
        for(auto it : edges){
            if(uf.Union(it[0],it[1]))n--;
        }
         return n;
    }
};
