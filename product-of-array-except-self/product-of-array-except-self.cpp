class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefix(size,1);
        vector<int> sufix(size,1);
        for(int i=1;i<size;i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        for(int i=size-2;i>=0;i--){
            sufix[i] = sufix[i+1] * nums[i+1];
        }
        vector<int> ans(size,1);
        for(int i=0;i<size;i++){
            ans[i] = prefix[i] * sufix[i];
        }
        return ans;
    }
};