class Solution {
public:
    int mod = 1e9+7;
    int concatenatedBinary(int n) {
        int len = 0;
        long answer = 0;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0){len++;}
            answer = ((answer<<len) | i)%mod;
        }
        return answer;
    }
};
