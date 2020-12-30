class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j){
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]=='0' or visited[i][j]==true){return;}
        visited[i][j] = true;
        dfs(grid,visited,i+1,j);
        dfs(grid,visited,i,j+1);
        dfs(grid,visited,i-1,j);
        dfs(grid,visited,i,j-1);   
    }
    int numIslands(vector<vector<char>>& grid) {
     vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),0));
    int isLands = 0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j] == '1' and !visited[i][j]){
                isLands++;
                dfs(grid,visited,i,j);
            }
        }
    }    
    return isLands;
    }
};
