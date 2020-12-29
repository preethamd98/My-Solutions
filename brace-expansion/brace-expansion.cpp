                while(s[i]!='}'){
                    if(s[i]!='}' and s[i]!='{' and s[i]!=','){
                        string temp;
                        temp.push_back(s[i]);
                        V.push_back(temp);
                    }
                    i++;
                }
                if(V.size()!=0){
                    sort(V.begin(),V.end());
                    VV.push_back(V);
                    V.clear();
                }
            }
            i++;
        }
        if(ss.size()!=0){
            vector<string> temp;
            sort(ss.begin(),ss.end());
            temp.push_back(ss);
            ss = "";
            VV.emplace_back(temp);
        }
        return VV;
    }
    
    
    
    void helper(vector<vector<string>>& V,int index,string s){
        if(index==V.size()){
            ans.push_back(s);
            return;
        }
        for(string c:V[index]){
            helper(V,index+1,s+c);
        }
    }
    
    bool check(string s){
        for(char c:s){
            if(c=='}' or c=='{' or c==','){
                return false;
            }
        }
        return true;
    }
    
    vector<string> expand(string S) {
        if(check(S)){
            vector<string> V;
            V.push_back(S);
            return V;
        }
        vector<vector<string>> v = converter2(S);
        helper(v,0,"");
        return ans;
    }
};
