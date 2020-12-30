class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> startTimes;
        vector<int> endTimes;
        int count = 0;
        for(auto interval : intervals) {
            startTimes.push_back(interval[0]);
            endTimes.push_back(interval[1]);
        }
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());
        
        int i = 0, j = 0;
        int globalMax = 0;
        while(i < startTimes.size() and j < endTimes.size()) {
            if(startTimes[i] < endTimes[j]) {
                count++;
                globalMax = max(globalMax, count); 
                i++;
            }
            else {
                count--;
                j++;
            }
        }
        return globalMax;
    }
};
​
​
