class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int size = nums.size();
        for(int i=0;i<size;i++){
            for(int j=0;j<size-i-1;j++){
                nums[j] = (nums[j] + nums[j+1])%10;
            }
        }
        return nums[0];
    }
};