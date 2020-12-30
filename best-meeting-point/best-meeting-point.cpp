class Solution {
public:
    
    int dist(vector<int> P1,vector<int> P2){
        return abs(P1[0] - P2[0]) + abs(P1[1] - P2[1]);
    }
    
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows;
        vector<int> cols;
        vector<vector<int>> points;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0){
                    rows.push_back(i);
                    cols.push_back(j);
                    points.push_back({i,j});
                }
            }
        }
        
        sort(cols.begin(),cols.end());
        int middCol = cols[cols.size()/2];
        
        sort(rows.begin(),rows.end());
        int middRow = rows[rows.size()/2];
        
        int distance = 0;
        for(auto it:points){
            distance += dist({middRow,middCol},it);
        }
        
        return distance;
        
        
    }
};
