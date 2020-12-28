class Solution {
public:
    int counter = 0;
    void helper(int N,int pos,vector<int> V){
        if(pos>N){
            counter++;
            return;
        }
        for(int i=1;i<=N;i++){
            if(V[i]==0 and (i%pos==0 || pos%i==0)){
                V[i] = 1;
                helper(N,pos+1,V);
                V[i] = 0;
            }
        }
    }
    int countArrangement(int N) {
        vector<int> v(N+1);
        helper(N,1,v);
        return counter;
    }
};
