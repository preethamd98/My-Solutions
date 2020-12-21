class Solution {
public:
    string s = "";
    string nums(string number){
        string s = "";
        for(auto c:number){
            if(c!='-' and c!=' '){
                s+=c;
            }
        }
        return s;
    }
    void format(string S,int size,int index){
        if(size==4){
            s = s + "-" +S[index]+S[index+1] + "-" +S[index+2]+S[index+3];
            return;
        }
        else if(size==2){
            s = s + "-" + S[index]+S[index+1];
            return;
        }
        else if(size==0){return;}
        s = s+"-"+S[index]+S[index+1]+S[index+2];
        format(S,size-3,index+3);
    }
    
    string reformatNumber(string number) {
        string newNumber = nums(number);
        format(newNumber,newNumber.size(),0);
        return s.substr(1);
    }
};
