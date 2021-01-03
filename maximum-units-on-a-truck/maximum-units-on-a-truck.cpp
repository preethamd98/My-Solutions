class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        if(boxTypes.size()==0){return 0;}
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>& A,vector<int>& B){return A[1]>B[1];});
        int score = 0;
        int i = 0;
        while(i<boxTypes.size() and truckSize>0){
            int val = min(boxTypes[i][0],truckSize);
            score += val*boxTypes[i][1];
            truckSize -= boxTypes[i][0];
            i++;
        }
        return score;
    }
};
