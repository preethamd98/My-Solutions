class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<bool>> BB(n,vector<bool>(m,false));
        for(auto it:indices){
            int r = it[0];
            int c = it[1];
            for(int i=0;i<m;i++){BB[r][i] = !BB[r][i];}
            for(int i=0;i<n;i++){BB[i][c] = !BB[i][c];}
        }
        int sol = 0;
        for(auto it:BB){
            for(auto it2:it){
                sol+=it2;
            }
        }
        return sol;
    }
};
