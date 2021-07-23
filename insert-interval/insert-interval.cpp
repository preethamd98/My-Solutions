class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> results;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][1] < newInterval[0]){
                results.push_back(intervals[i]);
            }
            else if(newInterval[1] < intervals[i][0]){
                results.push_back(newInterval);
                newInterval = intervals[i];
            }
            else{
                newInterval[0] = min(newInterval[0],intervals[i][0]);
                newInterval[1] = max(newInterval[1],intervals[i][1]);
            }
        }
        results.push_back(newInterval);
        return results;
    }
};