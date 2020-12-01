class Solution {
public:
    int numDecodings(string s) {
        int size = s.length();
        vector<int> dp(size+1,1);
        if(s[0] == '0'){
            return 0;
        }
        for(int i=2;i<=size;i++){
            if(s[i-1]=='0'){
                int number = stoi(s.substr(i-2,2));
                if(number>=10 and number<=26){
                    dp[i] = dp[i-2];
                }
                else{
                    dp[i] = 0;
                }
            }
            else{
                dp[i] = dp[i-1];
                int number = stoi(s.substr(i-2,2));
                if(number>=10 and number<=26){
                    dp[i]+=dp[i-2];
                }
            }
        }
        return dp[size];
    }
};
