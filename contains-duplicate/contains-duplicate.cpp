class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> S;
        for(int i:nums){
            if(S.find(i)!=S.end()){
                return 1;
            }
            S.insert(i);
        }
        return 0;
    }
};