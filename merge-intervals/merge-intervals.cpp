class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            auto current = ans.back();
            ans.pop_back();
            if(current[1]>=intervals[i][0]){
                current[1] = max(current[1],intervals[i][1]);
                ans.push_back(current);
            }
            else{
                ans.push_back(current);
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
