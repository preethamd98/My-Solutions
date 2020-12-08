class Solution {
public:
    int dp[105][105];
    vector<int> A;
    int triangulate(int i,int j){
        if(j<i+2){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int mini = INT_MAX;
        for(int k=i+1;k<j;k++){
            mini = min(mini,triangulate(i,k)+A[i]*A[j]*A[k]+triangulate(k,j));
        }
        return dp[i][j] = mini;
    }
    int minScoreTriangulation(vector<int>& V) {
        A = V;
        memset(dp,-1,sizeof(dp));
        return triangulate(0,V.size()-1);
    }
};
