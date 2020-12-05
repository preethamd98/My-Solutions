class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0){return false;}
        sum = sum/2;
        vector<bool> dp(sum+1,false);
        dp[0] = 1;
        for(int j:nums){
            for(int i = sum;i>=j;i--){
                dp[i] = dp[i] || dp[i-j];
            }
        }
        return dp[sum];
    }
};
