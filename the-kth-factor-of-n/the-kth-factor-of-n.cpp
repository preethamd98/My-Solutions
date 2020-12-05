class Solution {
public:
    int kthFactor(int n, int k) {
        int K = 0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                K++;
            }
            if(K==k){
                return i;
            }
        }
        return -1;
    }
};
