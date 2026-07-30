class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[j][n-1-i]=matrix[i][j];
            }
        }
        matrix=ans;
    }
};
// 0,0  0,2
// 0,1  1,2
// 0,2  2,2


//1,0 0,1
//1,1 1,1
//1,2 2,1

//2,0  0,0
//2,1  1,0
//2,2  2,0