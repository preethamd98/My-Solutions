class Solution {
public:
    int dp[600][600];
    vector<int> A;
    int triangulate(int i,int j){
        if(j<i+2){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int mini = INT_MIN;
        for(int k=i+1;k<j;k++){
            mini = max(mini,triangulate(i,k)+A[i]*A[j]*A[k]+triangulate(k,j));
        }
        return dp[i][j] = mini;
    }
    int maxCoins(vector<int>& V) {
        A.push_back(1);
        for(int i:V){A.push_back(i);}
        A.push_back(1);
        memset(dp,-1,sizeof(dp));
        return triangulate(0,A.size()-1);
    }
};
