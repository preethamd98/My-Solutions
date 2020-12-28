class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int F = 1;
        int L = n;
        bool ss = true;
        for(int i{0};i<k;i++){
            if(ss){
                ans.push_back(F);
                F++;
            }
            else{
                ans.push_back(L);
                L--;
            }
            ss = !ss;
        }
        if(k%2==0){
        for(int i=L;i>=F;i--){
            ans.push_back(i);
            }
            return ans;
        }
        for(int i=F;i<=L;i++){
            ans.push_back(i);
        }
        return ans;
    }
};
