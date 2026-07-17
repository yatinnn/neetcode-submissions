class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inDegree(numCourses,0);
        vector<vector<int>>adjL(numCourses);

        for(auto it : prerequisites){
            inDegree[it[1]]++;
            adjL[it[0]].push_back(it[1]);
        }

        queue<int>q;

        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0)q.push(i);
        }
        int finish=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            finish++;
            for(auto it : adjL[node]){
                inDegree[it]--;
                if(inDegree[it]==0)q.push(it);
            }
        }
        return finish==numCourses;
    }
};
