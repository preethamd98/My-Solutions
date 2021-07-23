class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = INT_MIN;
        int i = 0;
        int j = 0;
        int sum = 0;
        int n = nums.size();
        while(i < n){
            sum = 0;            
            while(j < n){
                sum += nums[j];
                maximum = max(sum,maximum);
                if(nums[j] > sum){
                    break;
                }
                j++;
            }
            i = j;
        }
        return maximum;
    }
};