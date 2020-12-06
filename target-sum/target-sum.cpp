class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        long long sum = accumulate(nums.begin(),nums.end(),0);
        if(((sum+S))%2!=0 or sum<S){return 0;}
        int target = (sum+S)/2;
        vector<double> dp(target+1,0);
        dp[0] = 1;
        for(int i:nums){
            for(int j=target;j>=i;j--){
                dp[j] += dp[j-i];
            }
        }
        return dp[target];
    }
};
