class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& M,unordered_set<int>& S,int i){
        S.insert(i);
        for(int e:M[i]){
            if(S.find(e)==S.end()){
                dfs(M,S,e);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> M;
        unordered_set<int> S;
        int counter = 0;
        for(auto e:edges){
            M[e[0]].push_back(e[1]);
            M[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++){
            if(S.find(i)==S.end()){
                counter++;
                dfs(M,S,i);
            }
        }
        return counter;
    }
};
