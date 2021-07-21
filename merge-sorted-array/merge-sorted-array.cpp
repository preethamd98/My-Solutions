class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums(m+n,0);
        int i=0;
        int j=0;
        int k=0;
        while(i<m and j<n){
            if(nums1[i] <= nums2[j]){
                nums[k++] = nums1[i];
                i++;
            } 
            else{
                nums[k++] = nums2[j];
                j++;
            }
        }
        while(i<m){
            nums[k++] = nums1[i++];
        }
        while(j<n){
            nums[k++] = nums2[j++];
        }
        nums1 = nums;
    }
};