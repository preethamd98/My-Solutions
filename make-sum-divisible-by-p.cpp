class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        
        for(int i:nums){
            sum = (sum+i)%p;
        }
        
        int excess = sum%p;
        unordered_map<int,int> M = {{0,-1}};
        int s = 0;
        int window_size = INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            s = (s + nums[i])%p;
            M[s] = i;
            int required = (s-sum+p)%p;
            if(M.count(required)){
                window_size = min(window_size, i - M[required]);
            }
        }
        return window_size>=nums.size()?-1:window_size;
    }
};
