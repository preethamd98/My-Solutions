class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int times = 0;
        for(int i=1;i<p.size();i++){
            times += max(abs(p[i][0] - p[i-1][0]),abs(p[i][1] - p[i-1][1]));
        }
        return times;
    }
};
