class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int dimAi = A.size();
        int dimAj = A[0].size();
        int dimBi = B.size();
        int dimBj = B[0].size();
        vector<vector<int>> AB(dimAi,vector<int>(dimBj,0));
        unordered_map<int,unordered_map<int,int>> sparseB;
        for(int i=0;i<dimBi;i++){
            for(int j=0;j<dimBj;j++){
                sparseB[i][j] = B[i][j];
            }
        }
        
        for(int i=0;i<dimAi;i++){
            for(int j=0;j<dimBj;j++){
                for(int k=0;k<A[0].size();k++){
                    AB[i][j] += A[i][k]*sparseB[k][j];
                }
            }
        }
        return AB;
    }
};
