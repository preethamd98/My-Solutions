class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> buckets(101,0);
        for(int i:nums){
            buckets[i]++;
        }
        for(int i=1;i<101;i++){
            buckets[i] += buckets[i-1];
        }
        
        for(int i=0;i<nums.size();i++){
            int temp = nums[i];
            nums[i] = temp==0?0:buckets[temp-1];
        }
        return nums;
    }
};
