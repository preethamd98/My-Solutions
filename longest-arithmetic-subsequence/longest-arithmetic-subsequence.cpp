class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(2000, 0));
        int maxLength = 0;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<i;j++){
                int diff = A[j]-A[i]+1000;
                dp[i][diff] = dp[j][diff]?dp[j][diff]+1:2;
                maxLength = max(dp[i][diff],maxLength);
            }
        }
        return maxLength;
    }
};
