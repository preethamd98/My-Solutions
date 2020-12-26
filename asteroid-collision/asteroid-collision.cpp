class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> V;
        for(int i:asteroids){
            if(i>0){V.push_back(i);}
            else{
                while(!V.empty() and V.back()>0 and V.back()<abs(i)) V.pop_back();
                if(V.empty() || V.back()<0){V.push_back(i);}
                else if(V.back()==-1*i){V.pop_back();}
            }
        }
        return V;
    }
};
