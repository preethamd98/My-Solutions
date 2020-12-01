class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        int maxi = 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++){
                if(A[i]==B[j]){
                    dp[i+1][j+1] = 1+dp[i][j];
                    maxi = max(dp[i+1][j+1],maxi);
                }
            }
        }
        return maxi;
    }
};
