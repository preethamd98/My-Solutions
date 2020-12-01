class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> M;
        for(int i:nums){
            M[i]++;
        }
        int maxi = 0;
        for(auto it:M){
            int key = it.first;
            if(M[key]>0 and M[key+1]>0){
                maxi = max(maxi,M[key]+M[key+1]);
            }
        }
        return maxi;
    }
};
