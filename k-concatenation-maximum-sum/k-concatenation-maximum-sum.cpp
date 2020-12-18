class Solution {
public:
    long e = 1e9+7;
    int maxSubArray(vector<int>& V){
        int maxSoFar = V[0];
        int currentMax = V[0];
        for(int i=1;i<V.size();i++){
            maxSoFar = max(maxSoFar+V[i],V[i]);
            maxSoFar %= e;
            currentMax = max(currentMax,maxSoFar);
            currentMax %= e;
        }
        return currentMax;
    }
    vector<int> transform(vector<int>&arr, int k){
        vector<int> V;
        for(int i=0;i<k;i++){
            for(int j:arr){
                V.push_back(j);
            }
        }
        return V;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long sum = accumulate(arr.begin(),arr.end(),0);
        vector<int> t = transform(arr,2);
        int ans = maxSubArray(t);
        if(ans<0){return 0;}
        return (ans + ((sum>0)?sum*(k-2):0))%e;
    }
};
