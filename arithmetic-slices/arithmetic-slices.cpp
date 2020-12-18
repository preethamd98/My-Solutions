class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n+1,0);
        int slices = 0;
        for(int i{1};i<n-1;i++){
            if(A[i] - A[i-1] == A[i+1] - A[i]){
                dp[i] = dp[i-1]+1;
                slices += dp[i];
            }
        }
        return slices;
    }
};
