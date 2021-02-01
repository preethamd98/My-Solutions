class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        if(nums[low] <= nums[high]){return nums[low];}
        while(low + 1 < high){
            int mid = low + (high - low)/2; 
            if(nums[mid] > nums[mid+1]){
                return nums[mid+1];
            }
            else if(nums[mid] > nums[high]){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        return min(nums[low],nums[high]);
    }
};