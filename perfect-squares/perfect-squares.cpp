class Solution {
public:
    int numSquares(int n) {
        int root = sqrt(n)+1;
        vector<int> V;
        for(int i=1;i<=root;i++){
            V.push_back(i*i);
        }
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i=0;i<=n;i++){
            for(int j:V){
                if(i-j>=0){
                    dp[i] = min(dp[i],dp[i-j]+1);
                }
            }
        }
        return dp[n];
    }
};
