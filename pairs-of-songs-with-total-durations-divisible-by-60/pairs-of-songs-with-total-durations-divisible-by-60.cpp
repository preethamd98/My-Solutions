class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> M;
        int counter = 0;
        for(int t:time){
            int transformedTime = t%60;
            int otherTime = (transformedTime==0)?0:60 - transformedTime;
            counter += M[otherTime];
            M[transformedTime]++;
        }
        return counter;
    }
};
