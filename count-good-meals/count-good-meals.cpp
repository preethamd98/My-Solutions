class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        vector<long> V;
        long pow = 1;
        for(int i=1;i<32;i++){
            V.push_back(pow);
            pow *= 2;
        }
        int counter = 0;
        unordered_map<long,int> M;
        for(int i:deliciousness){
            for(int j:V){
                int diff = j - i;
                if(diff>=0 and M.find(diff)!=M.end()){
                    counter += M[diff];
                    counter = counter%(1000000007);
                }
            }
            M[i]++;
        }
        return counter;
    }
};
