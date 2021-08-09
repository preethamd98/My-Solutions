class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths(m,vector<int>(n,0));
        paths[0][0] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i-1>=0){paths[i][j] += paths[i-1][j];}
                if(j-1>=0){paths[i][j] += paths[i][j-1];}
            }
        }
        return paths[m-1][n-1];
    }
};