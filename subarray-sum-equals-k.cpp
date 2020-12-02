class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> M;
        M[0] = 1;
        int sum = 0;
        int counter = 0;
        for(int i:nums){
            sum += i;
            if(M.count(sum-k)){
                counter+=M[sum-k];
            }
            M[sum]++;
        }
        return counter;
    }
};
