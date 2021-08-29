class Solution {
public:
    int fib(int n) {
        if(n == 0){return 0;}
        vector<int> fibGen(n+1);
        fibGen[0] = 0;
        fibGen[1] = 1;
        for(int i=2;i<=n;i++){
            fibGen[i] = fibGen[i-1] + fibGen[i-2];
        }
        return fibGen[n];
    }
};