class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        int answer = 1;
        vector<vector<int>> dp(n,vector<int> (n,2));
        unordered_map<int,int> indices;
        for(int i=0;i<A.size();i++){
            indices[A[i]] = i;
            dp[i][0] = 1;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum = A[i] + A[j];
                if(indices.count(sum)){
                    dp[j][indices[sum]] = 1 + dp[i][j];
                    // answer = max(answer,max({dp[i][j],dp[j][indices[sum]]}));
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                answer = max(answer,dp[i][j]);
            }
        }
        
        return answer>=3?answer:0;
    }
};
