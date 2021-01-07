class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<int> low;
    vector<int> order;
    vector<vector<int>> bridges;
    int count = 0;
    void dfs(int currentNode,int parent=-1){
        visited[currentNode] = true;
        low[currentNode] = order[currentNode] = ++count;
        for(int adjNode:graph[currentNode]){
            if(!visited[adjNode]){
            dfs(adjNode,currentNode);
            low[currentNode] = min(low[currentNode],low[adjNode]);
            if(order[currentNode] < low[adjNode]){
                bridges.push_back({currentNode,adjNode});
            }
            }
            else if(adjNode != parent){
                low[currentNode] = min(low[currentNode],order[adjNode]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.resize(n);
        visited.resize(n,false);
        low.resize(n);
        order.resize(n);
        
        for(auto i:connections){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
