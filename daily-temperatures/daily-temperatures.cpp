class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
     int size = T.size();
     stack<int> S;
     vector<int> V(size,0);
     for(int i=0;i<size;i++){
         while(S.size()>0 and T[S.top()] < T[i]){
             V[S.top()] = i - S.top();
             S.pop();
         }
         S.push(i);
     }
        return V;
    }
};
