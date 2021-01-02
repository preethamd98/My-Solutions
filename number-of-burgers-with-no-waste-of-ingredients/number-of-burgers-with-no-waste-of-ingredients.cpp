class Solution {
public:
    vector<int> numOfBurgers(int ts, int cs) {
        if(ts==0 or cs==0){return {0,0};}
        int cb = cs;
        for(int i=0;i<cb;i++){
            int small = cb - i;
            if(ts == 4*i + 2*small){
                return {i,small};
            }
        }
        return {};
    }
};
