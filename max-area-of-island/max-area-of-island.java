class Solution {
    int area(int[][] visited, int[][] grid, int i,int j){
        if(i<0 || j<0 || i>=visited.length || j>=visited[0].length || visited[i][j] == 1 || grid[i][j] == 0){
            return 0;
        }
        visited[i][j] = 1;
        return 1 + area(visited,grid,i,j+1) + area(visited,grid,i+1,j) + area(visited,grid,i-1,j) + area(visited,grid,i,j-1);
    }
    public int maxAreaOfIsland(int[][] grid) {
        int maxArea = 0;
        int m = grid.length;
        int n = grid[0].length;
        int[][] visited = new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    maxArea = Math.max(maxArea,area(visited,grid,i,j));
                }
            }
        }
        return maxArea;
    }
}