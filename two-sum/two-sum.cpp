class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // O(n^2)
        // vector<int> ans; 
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i] + nums[j] == target){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {};
        
    
        // //O(nlog(n))
        // sort(nums.begin(),nums.end());
        // int i=0,j=nums.size()-1;
        // while(i<j){
        //     if(nums[i] + nums[j] == target){
        //         return {i,j};
        //     }
        //     else if(nums[i] + nums[j] < target){
        //         i++;
        //     }
        //     else{
        //         j--;
        //     }
        // }
        // return {};
       unordered_map<int,int> S;
        for(int i=0;i<nums.size();i++){
            if(S.find(target - nums[i])!=S.end()){
                return {i,S[target - nums[i]]};
            }
            else{
                S[nums[i]] = i;
            }
        }
        return {};
           
    }
};