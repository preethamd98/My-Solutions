class Solution {
public:
    string question = "";
    bool validate(string a,string b){
        string s = "";
        for(char c:a){
            if(c!='.'){s+=c;}
        }
        return s==b;
    }
    vector<string> IP;
    void helper(string s,string answer,int counter){
        if(s.size()==0 and counter==4){answer.pop_back();
            if(validate(answer,question)){
                IP.push_back(answer);
            }return;}
        else if(s.size()>0 and counter==4){return;}
        if(s.size()>=1){
            int a = stoi(s.substr(0,1));
            if(a>=0 and a<=255){
                 helper(s.substr(1),answer+to_string(a)+".",counter+1);
            }
        }
        if(s.size()>=2){
        int a = stoi(s.substr(0,2));
            if(a>=0 and a<=255){
                 helper(s.substr(2),answer+to_string(a)+".",counter+1);
            }
        }
        if(s.size()>=3){
        int a = stoi(s.substr(0,3));
            if(a>=0 and a<=255){
                 helper(s.substr(3),answer+to_string(a)+".",counter+1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        this->question = s;
        helper(s,"",0);
        return IP;
    }
};
