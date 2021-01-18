class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLength = 1;
        vector<int> V(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            int count = 1;
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    V[i] = max(V[i],1+V[j]);
                    maxLength = max(V[i],maxLength);
                }
            }
        }
        return maxLength;
    }
};
