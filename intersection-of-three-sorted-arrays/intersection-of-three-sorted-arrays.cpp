class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        set<int> s2(arr2.begin(),arr2.end());
        set<int> s3(arr3.begin(),arr3.end());
        vector<int> answer;
        for(int i:arr1){
            if(s2.find(i)!=s2.end() and s3.find(i)!=s3.end()){
                answer.push_back(i);
            }
        }
        return answer;
    }
};
