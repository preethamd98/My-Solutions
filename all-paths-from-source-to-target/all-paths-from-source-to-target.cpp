class Solution {
public:
    vector<vector<int>> paths;
    void dfs(vector<vector<int>>& graph,int source,int destination,vector<int>& path){
        if(source==destination){
            paths.push_back(path);
            return;
        }
        for(int i:graph[source]){
            path.push_back(i);
            dfs(graph,i,destination,path);
            path.pop_back();
        }
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path = {0};
        dfs(graph,0,graph.size()-1,path);
        return paths;
    }
};
