class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        unordered_map<int,vector<int>> M;
        for(auto i:prerequisites){
            inDegree[i[0]]++;
            M[i[1]].push_back(i[0]);
        }
        
        queue<int> Q;
        
        for(int i=0;i<inDegree.size();i++){
            if(inDegree[i]==0){
                Q.push(i);
            }
        }
        
        int coursePath = 0;
        
        while(!Q.empty()){
            coursePath++;
            int top = Q.front();
            Q.pop();
            if(M.find(top)==M.end()){continue;}
            for(int i:M[top]){
                inDegree[i]--;
                if(inDegree[i]==0){
                    Q.push(i);
                }
            }
        }
        return coursePath == numCourses;
    }
};
