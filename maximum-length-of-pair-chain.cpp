class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size()==0){return 0;}
        sort(pairs.begin(),pairs.end());
        int size = pairs.size();
        int ans = 1;
        vector<int> dp(size,1);
        for(int i=1;i<size;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i] = max(dp[i],dp[j]+1);
                    ans = max(dp[i],ans);
                }
            }
        }
        return ans;
    }
};
