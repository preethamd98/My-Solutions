class Solution {
public:
    unordered_map<int,int> cache;
    int helper(vector<int>& nums,int index=0){
        if(index>=nums.size()){return 0;}
        if(cache.find(index)!=cache.end()){return cache[index];}
        return cache[index] = max(nums[index]+helper(nums,index+2),helper(nums,index+1));
    }
    int rob(vector<int>& nums) {
        return helper(nums);
    }
};