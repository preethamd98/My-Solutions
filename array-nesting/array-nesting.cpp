class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int len = 0;
        int size = nums.size();
        vector<bool> visited(size,false);
        for(int i:nums){
            int current = i;
            int counter = 0;
            while(visited[current]!=true){
                visited[current] = true;
                current = nums[current];
                counter++;
            }
            len = max(len,counter);
        }
        return len;
    }
};
