class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> PQ;
        if(a>0){PQ.push({a,'a'});}
        if(b>0){PQ.push({b,'b'});}
        if(c>0){PQ.push({c,'c'});}
        string S;
        while(PQ.size()>1){
            auto first = PQ.top();PQ.pop();
            auto second = PQ.top();PQ.pop();
            if(first.first >=2){
                S += first.second;
                S += first.second;
                first.first -= 2;
            }
            else{
                S+=first.second;
                first.first -= 1;
            }
            if(second.first >= 2 and second.first>=first.first){
                S += second.second;
                S += second.second;
                second.first -= 2;
            }
            else{
                S+=second.second;
                second.first -= 1;
            }
            if(first.first>0){PQ.push(first);}
            if(second.first>0){PQ.push(second);}
        }
        auto top = PQ.top();
        if(top.second!=S.back()){for(int i=0;i<min(2,top.first);i++){S+=top.second;}}
        return S;
    }
