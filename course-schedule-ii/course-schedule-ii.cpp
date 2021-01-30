class Solution {
public:
    vector<int> Order;
    unordered_map<int,vector<int>> graph;
    unordered_set<int> visited;
    unordered_set<int> recursive;
    bool dfs(int node){
        if(recursive.find(node)!=recursive.end()){return false;}
        if(visited.find(node)!=visited.end()){return true;}
        visited.insert(node);
        recursive.insert(node);
        for(int i:graph[node]){if(!dfs(i)){return false;}}
        recursive.erase(node);
        Order.push_back(node);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto it:prerequisites){graph[it[0]].push_back(it[1]);}
        for(int i=0;i<numCourses;i++){if(!dfs(i)){return vector<int>();}}
        return Order;
    }
};