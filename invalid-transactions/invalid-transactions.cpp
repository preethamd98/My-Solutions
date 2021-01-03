class Solution {
public:
    string makeString(vector<string> vecStr) {
        string res = "";
        for(auto str : vecStr) {
            res += (str + ",");
        }
        return res.substr(0, res.size()-1);
    }
    
    vector<string> invalidTransactions(vector<string>& transactions) {
        set<string> S;
        unordered_map<string, vector<vector<string>>> M; // Name, transaction Array -> each transaction is already split and stored
        for(auto i:transactions){
            stringstream ss(i);
            vector<string> V;
            string temp;
            while(getline(ss,temp,',')){V.push_back(temp);}
            if(stoi(V[2]) > 1000) {
                S.insert(i);
            }
            if(M.find(V[0]) != M.end()) {
                for(auto tran : M[V[0]]) {
                    if((tran[3] != V[3]) && (abs(stoi(tran[1]) - stoi(V[1])) <= 60)) {
                        S.insert(makeString(tran));
                        S.insert(i);
                    }
                }
            }
            M[V[0]].push_back(V);
        }
    
        vector<string> res(S.begin(), S.end());
        return res;
    }
};
