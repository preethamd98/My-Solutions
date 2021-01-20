class Solution {
public:
    vector<int> V;
    unordered_map<int,vector<int>> M;
    void dfs(int target){
        V.push_back(target);
        if(M.find(target)==M.end()){
            return;
        }
        for(int i:M[target]){
            dfs(i);
        }
    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        for(int i=0;i<pid.size();i++){
            M[ppid[i]].push_back(pid[i]);
        }
        dfs(kill);
        return V;
    }
};
