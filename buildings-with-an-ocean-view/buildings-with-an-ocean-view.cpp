class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> buildings;
        stack<int> S;
        buildings.push_back(heights.size()-1);
        S.push(heights.size()-1);
        for(int i=heights.size()-2;i>=0;i--){
            while(S.size()>0 and heights[i] > heights[S.top()]){
                S.pop();
            }
            if(S.size() == 0){
                buildings.push_back(i);
            }
            S.push(i);
        }
        sort(buildings.begin(),buildings.end());
        return buildings;
    }
};