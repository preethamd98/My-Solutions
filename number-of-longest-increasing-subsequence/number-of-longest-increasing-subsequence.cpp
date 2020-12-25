class Solution {
public:
    int findNumberOfLIS(vector<int>& V) {
    int n = V.size();
    int maxLen = 1;
    vector<int> dp(n, 1);
    vector<int> len(n,1);
    int maxCounter = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (V[j] < V[i]) {
                if(dp[j]+1>dp[i]){
                    dp[i] = 1 + dp[j];
                    len[i] = len[j];
                    maxLen = max(maxLen,dp[i]);
                }
                else if(dp[i] == 1 + dp[j]){
                    len[i] += len[j];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dp[i] == maxLen){
            maxCounter += len[i];
        }
    }
    return maxCounter;
    }
};
