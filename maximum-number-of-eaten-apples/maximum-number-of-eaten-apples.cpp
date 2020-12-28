class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        map<int,int> eaten;
        int l = apples.size();
        int counter = 0;
        for(int i=0;i<l or eaten.upper_bound(i)!=eaten.end();i++){
            if(i<l){
                eaten[i+days[i]] = apples[i];
            }
            auto V = eaten.upper_bound(i);
            if(V!=eaten.end()){
                counter++;
                if(V->second>1){
                    eaten[V->first]--;
                }
                else{
                    eaten.erase(V->first);
                }
            }
        }
        return counter;
    }
};
