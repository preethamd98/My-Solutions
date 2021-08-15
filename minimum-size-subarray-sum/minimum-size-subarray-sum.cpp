class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int runningSum = 0;
        int size = nums.size();
        int start = 0;
        int length = INT_MAX;
        for(int end=0;end<size;end++){
            runningSum += nums[end];
            while(runningSum >= target){
                length = min(length,end-start+1);
                runningSum -= nums[start];
                start++;
            }
        }
        return length==INT_MAX?0:length;
    }
};