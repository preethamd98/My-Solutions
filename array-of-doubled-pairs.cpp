class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        int size = A.size();
        map<int,int> M;
        for(int i:A){
            M[i]++;
        }
        
        int counter = 0;
        
        for(auto it = M.begin();it!=M.end();it++){
            int key = it->first;
            int value = it->second;
            if(key==0){
                counter += value/2;
                M[key] = 0;
            }
            else if(M.find(key*2)!=M.end()){
                int removedValue = min(value,M[2*key]);
                M[key]-=removedValue;
                M[2*key]-=removedValue;
                counter+=removedValue;
            }
        }
        return (counter == size/2);
    }
};
