class Solution {
public:
        int lcs(string a, string b) {
        int size_a = a.size();
        int size_b = b.size();
        if(size_a==0 || size_b==0){return 0;}
        vector<vector<int>> dp(size_a + 1, vector<int>(size_b + 1, 0));
        for (int i = 1; i <= size_a; i++) {
            for (int j = 1; j <= size_b; j++) {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[size_a][size_b];
    }
    int longestPalindromeSubseq(string s) {
        string s2 = string(s);
        reverse(s2.begin(),s2.end());
        return lcs(s,s2);
    }
};
