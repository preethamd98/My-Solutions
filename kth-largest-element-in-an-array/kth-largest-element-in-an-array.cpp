class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i:nums){
            if(pq.size()<k){        // Insert the number
                pq.push(i);
            }
            else if(pq.size()==k){ // Evict if required
                if(pq.top()<i){
                    pq.pop();
                    pq.push(i);
                }
            }
        }
        return pq.top();
    }
};
