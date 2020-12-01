class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int preOdd = 0;
        int preEven = 0;
        int suOdd = 0;
        int suEven = 0;
        int counter = 0;
        
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                preEven+=nums[i];
            }
            else{
                preOdd+=nums[i];
            }
        }
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                preEven-=nums[i];
            }
            else{
                preOdd-=nums[i];
            }
            if(preEven+suEven == preOdd+suOdd){counter++;}
            
            if(i%2!=0){
                suEven+=nums[i];
            }
            else{
                suOdd+=nums[i];
            }
            
        }
        return counter;
    }
};
