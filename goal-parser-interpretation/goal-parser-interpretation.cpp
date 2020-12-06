class Solution {
public:
    //"G", "()" and/or "(al)" 
    string interpret(string command) {
        string s = "";
        for(int i=0;i<command.size();){
            if(command[i]=='G'){
                s += 'G';
                i+=1;
            }
            else if(command[i]=='(' and i+1<command.size() and command[i+1]==')'){
                s+= 'o';
                i+=2;
            }
            else if(command[i]=='(' and i+3<command.size() and command[i+1] == 'a' and command[i+2]=='l' and command[i+3]==')' ){
                s+="al";
                i+=4;
            }
        }
        return s;
    }
};
