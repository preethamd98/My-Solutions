class Solution {
public:
    
    queue<pair<int,int>> pacific;
    queue<pair<int,int>> atlantic;
    
    int rows,cols;
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        this->rows = heights.size();
        this->cols = heights[0].size();
        
        for(int i=0;i<rows;i++){
            pacific.push({i,0});
            atlantic.push({i,cols-1});
        }
        
        for(int i=0;i<cols;i++){
            pacific.push({0,i});
            atlantic.push({rows-1,i});
        }
        
        vector<vector<bool>> p = bfs(heights,pacific);
        vector<vector<bool>> a = bfs(heights,atlantic);
        
        vector<vector<int>> ans;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(p[i][j] and a[i][j]){ans.push_back({i,j});}
            }
        }
        return ans;
    }
    
    vector<vector<bool>> bfs(vector<vector<int>>& heights,queue<pair<int,int>> q){
        vector<vector<int>> directions = {{0,-1},{-1,0},{1,0},{0,1}};
        vector<vector<bool>> ans(rows,vector<bool>(cols,false));
        while(!q.empty()){
            pair<int,int> head = q.front();
            q.pop();
            ans[head.first][head.second] = true;
            for(auto i:directions){
                int X = head.first + i[0];
                int Y = head.second + i[1];
                if(X<0 || X>=rows || Y<0 || Y>=cols){continue;}
                if(ans[X][Y]){continue;}
                if(heights[X][Y] < heights[head.first][head.second]){continue;}
                q.push({X,Y});
            }
        }
        return ans;
    }
};