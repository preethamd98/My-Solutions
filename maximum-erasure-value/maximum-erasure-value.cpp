class Solution {
public:
    int maximumUniqueSubarray(vector<int>& V){
    int i = 0;
    int j = 0;
    int sum = 0;
    int maxValue = 0;
    int n = V.size();
    unordered_set<int> S;
    for(int i=0;i<n;){
        if(S.find(V[i])==S.end()){
            sum+=V[i];
            S.insert(V[i]);
            i++;
        }
        else{
            while(S.find(V[i])!=S.end()){
                sum-=V[j];
                S.erase(V[j]);
                j++;
            }
        }
        maxValue = max(maxValue,sum);
    }
        return maxValue;
    }
​
};
