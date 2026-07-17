class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inDegree(numCourses,0);
        vector<vector<int>>adjL(numCourses);

        for(auto it : prerequisites){
            inDegree[it[0]]++;
            adjL[it[1]].push_back(it[0]);
        }

        queue<int>q;

        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0)q.push(i);
        }
        vector<int>ans;
        int finish=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            finish++;
            for(auto it : adjL[node]){
                inDegree[it]--;
                if(inDegree[it]==0)q.push(it);
            }
        }
         if (finish != numCourses) {
            return {};
        }
        return ans;
    }
};
