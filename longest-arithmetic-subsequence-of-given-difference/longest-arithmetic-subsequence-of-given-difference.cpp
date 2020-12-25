class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int len = 1;
        for(int i:arr){
            dp[i] = 1 + dp[i-difference];
            len = max(len,dp[i]);
        }
        return len;
    }
};
