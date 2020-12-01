class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int size = A.size();
        vector<int> dp1(size+1,1);
        vector<int> dp2(size+1,1);
        int maxi = 1;
        for(int i=0;i<size-1;i++){
            if((i%2==1 and A[i]>A[i+1]) or (i%2==0 and A[i]<A[i+1])){
                dp1[i+1] = dp1[i] + 1;
                maxi = max(maxi,dp1[i+1]);
            }
            else if((i%2==1 and A[i]<A[i+1]) or (i%2==0 and A[i]>A[i+1])){
                dp2[i+1] = dp2[i] + 1;
                maxi = max(maxi,dp2[i+1]);
            }
        }
        return maxi;
    }
};
